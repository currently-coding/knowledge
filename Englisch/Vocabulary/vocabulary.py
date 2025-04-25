import signal
import subprocess
from re import sub
from time import sleep
from requests import ConnectionError, get

in_filepath = "wordlist_mw.md"
out_filepath = "vocabulary_mw.md"
words_per_execution = 7
max_num_translations = 3
delay_per_request = 2

# vars
audio_british = "audio_british"
audio_american = "audio_american"

lin_base_url = "https://linguee-api.fly.dev"


# start server
def start_server():
    proc = subprocess.Popen(
        ["uvicorn", "linguee_api.api:app"],
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
    )
    # wait for server to start
    for _ in range(20):
        try:
            get("http://127.0.0.1:8000")
            print("Server is running...")
            break
        except ConnectionError:
            sleep(0.2)
    lin_base_url = "http://127.0.0.1:8000"
    return proc


def stop_server(server):
    print("Shutting down server...", end="")
    server.send_signal(signal.SIGINT)  # send SIGINT to stop uvicorn gracefully
    server.wait()
    print(" -> Success")


def request(url):
    while True:
        print(f"Trying to reach {url}")
        try:
            response = get(url)
        except ConnectionError:
            print("Connection failed. Retrying in 5 seconds.")
            sleep(5)
            continue
        if response.status_code == 404:
            return None
        if response.status_code == 200:
            break
        print(f"Request failed: Status Code <{response.status_code}>.")
        sleep(5)
    try:
        return response.json()
    except ValueError as e:
        print("Failed to parse JSON:", e)
        print("URL: ", url)
        print("DATA: ", response.text)
        raise e


def get_chosen_entry(data, pos):
    # excludes unwanted things e.g. 'stage direction'
    for entry in data:
        if entry.get("fl", None) == pos:
            return entry
    return None


def process_linguee(data, word):
    info = {}
    entry = {}
    entry = data[0]
    info["pos"] = entry.get("pos", "")

    info["word"] = entry.get("text", "N/A")
    # audio file
    audios = entry.get("audio_links", [])
    if not audios:
        audios = []
    for audio in audios:
        to_remove = "https://www.linguee.com/mp3/"
        if audio.get("lang", "") == "British English":
            info[audio_british] = audio.get("url").replace(to_remove, "")
        elif audio.get("lang", "") == "American English":
            info[audio_american] = audio.get("url").replace(to_remove, "")
    forms = entry.get("forms", [])
    if forms:
        info["forms"] = []
    for form in forms:
        info["forms"].append(form)

    # translation
    info["translation"] = []
    info["examples"] = []
    for trans in entry.get("translations", []):
        info["translation"].append(trans.get("text", ""))
        for ex in trans.get("examples", []):
            info["examples"].append(ex.get("src", ""))
    return info


def url(dictionary, word):
    match dictionary:
        case "api":
            return "https://api.dictionaryapi.dev/api/v2/entries/en/" + word
        case "linguee":
            lin_url = f"{lin_base_url}/api/v2/translations?query={word}&src=en&dst=de&guess_direction=false&follow_corrections=always"
            return lin_url


def format_to_flashcard(word):
    separator = "?"
    num_examples = 5
    num_definitions = 3
    num_translations = 3
    line = []
    if word["pos"] == "verb":
        word["word"] = "to " + word["word"]
    definition = ", ".join(word["definition"][:num_definitions])
    line.append(definition)
    line.append(separator)
    line.append(">[!vocab]- " + word["word"] + "(" + word["pos"] + ")")
    line.append(
        ">**Translations**: " + ", ".join(word["translation"][:num_translations])
    )
    if "forms" in word:
        forms = word["forms"]
        line.append("**Forms**: " + ", ".join(forms))
    if "phonetic" in word:
        line.append(">**Pronunciation**: " + word["phonetic"])
    if "audio_british" in word:
        link = word["audio_british"]
        audio_lin_be = f'<audio controls><source src="{link}" type="audio/mpeg">Unsupported.</audio>'
        line.append(">**Audio**: " + audio_lin_be)
    try:
        if word["examples"] != []:
            line.append(">>[!example]+ Examples")
            for n in range(num_examples):
                if n >= len(word["examples"]):
                    break
                line.append(">>- " + word["examples"][n])
    except KeyError:
        pass
    line = "\n".join(line) + "\n"
    return line


def checkout(lines):
    with open(out_filepath, "a") as f:
        print("Writing to output file...", end="")
        for line in lines:
            f.write(line)
            f.write("\n")
        print(" -> Success")

    print("Deleting words from input file...", end="")
    with open(in_filepath, "r") as fin:
        remaining = fin.readlines()[
            words_per_execution:
        ]  # keep only lines after the first `amount`

    with open(in_filepath, "w") as fout:
        fout.writelines(remaining)
    print(" -> Success")


def get_words(amount):
    print(f"Reading {amount} words from input file...", end="")
    with open(in_filepath, "r") as f:
        words = [next(f).strip() for _ in range(amount)]
    print(" -> Success.")
    return words


def process_dictapi(data, word, pos):
    info = {}
    info["definition"] = []
    for entry in data:
        meaning_entry = {}
        for m in entry.get("meanings", []):
            if m.get("partOfSpeech", "") == pos:
                meaning_entry = m
                break

        phonetic = entry.get("phonetic", None)
        if phonetic:
            info["phonetic"] = phonetic
        for definition in meaning_entry.get("definitions", []):
            defi = definition.get("definition", None)
            if not defi:
                continue
            defi = sub(r"\([^\s]*?\)", "", defi).strip()
            if defi != "":
                info["definition"].append(defi)
    return info


def merge(data1, data2, pos):
    master = {"pos": pos, **data1, **data2}
    # each word must have a definition to be valid
    return master if master.get("definition") else None


def main():
    try:
        proc = start_server()
    except:
        print('Setting up server failed.\nDefaulting to "https://linguee-api.fly.dev"')
        pass

    words = get_words(words_per_execution)
    flashcards = []
    for word in words:
        if delay_per_request != 0:
            print(f"Waiting for {delay_per_request} seconds.")
        sleep(delay_per_request)
        lin_data = request(url("linguee", word))
        api_data = request(url("api", word))
        if not lin_data or not api_data:
            print(f'Failed to retrieve information for "{word}" -> Skipped.')
            continue
        lin_info = process_linguee(lin_data, word)
        pos = lin_info["pos"]
        api_info = process_dictapi(api_data, lin_info["word"], pos)

        info = merge(lin_info, api_info, pos)
        if info:
            flashcards.append(format_to_flashcard(info))
    checkout(flashcards)
    try:
        stop_server(proc)
    except:
        pass


if __name__ == "__main__":
    main()
