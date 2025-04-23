from os import getenv
import signal
import subprocess
from re import sub
from time import sleep

from dotenv import load_dotenv
from requests import get, ConnectionError

load_dotenv()

# start server
proc = subprocess.Popen(
    ["uvicorn", "linguee_api.api:app"],
    stdout=subprocess.DEVNULL,
    stderr=subprocess.DEVNULL,
)
# wait for server to start
for _ in range(20):
    try:
        get("http://127.0.0.1:8000")  # adjust to actual endpoint
        break
    except ConnectionError:
        sleep(0.2)

dict_api_key = getenv("DICT_API_KEY")
in_filepath = "wordlist_mw.md"
out_filepath = "vocabulary_mw.md"
words_per_execution = 20
max_num_translations = 3
if not dict_api_key:
    raise ValueError("API key not found. Please set API_KEY in .env file.")


dictionary_base_url = "https://dictionaryapi.com/api/v3/references/collegiate/json/"
thesaurus_base_url = "https://dictionaryapi.com/api/v3/references/thesaurus/json/"


def request(url):
    """requests data from the provided url, returns json()"""
    response = None
    while not response:
        print(f"Trying to reach {url}")
        response = get(url)
        if response.status_code == 404:
            return None
        if response.status_code != 200:
            print(f"Request failed: Status Code <{response.status_code}>.")
            response = None
            print("Waiting for 5 seconds.")
            sleep(5)

    try:
        data = response.json()
    except ValueError as e:
        print("----")
        print("Failed to parse JSON:", e)
        print("URL: ", url)
        print("DATA: ", response.text)
        print("----")
        raise e

    print("Data has been received.")
    return data


def get_chosen_entry(data, pos):
    # excludes unwanted things e.g. 'stage direction'
    for entry in data:
        if entry.get("fl", None) == pos:
            return entry
    return None


def process_linguee(data, word, pos):
    info = {}
    entry = {}
    for entry in data:
        if entry.get("pos", "") == pos:
            data = entry
            break

    # audio file
    audios = entry.get("audio_links", [])
    if not audios:
        audios = []
    for audio in audios:
        to_remove = "https://www.linguee.com/mp3/"
        if audio.get("lang", "") == "British English":
            info["audio_british"] = audio.get("url").replace(to_remove, "")
        elif audio.get("lang", "") == "American English":
            info["audio_american"] = audio.get("url").replace(to_remove, "")
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


def process_mw(data, word, pos, num_definitions=3):
    """extracts data from json into dict"""
    if not data:
        print(" -> No data was received.")
        raise ValueError("Data is empty.")

    entry = data[0]

    if not isinstance(entry, dict):
        print(" -> Not found.")
        return entry  # return suggested word

    entry = get_chosen_entry(data, pos)
    if not entry:
        print(" -> Not found.")
        return None

    raw_id = entry["meta"]["id"]
    word_from_data = raw_id.split(":")[0] if ":" in raw_id else raw_id

    if word != word_from_data:
        print(f'Changed "{word}" to "{word_from_data}"')
        word = word_from_data

    # Definition
    definitions = entry.get("shortdef", ["N/A"])[:num_definitions]
    for i in range(len(definitions)):
        if ":" in definitions[i]:
            parts = definitions[i].split(":")
            definitions[i] = parts[0] + "(" + parts[1][1:] + ")"
        elif "—" in definitions[i]:
            parts = definitions[i].split("—")
            definitions[i] = parts[0] + "(" + parts[1] + ")"

    # Pronunciation
    pronunciation = entry.get("hwi", {}).get("prs", [{}])[0].get("mw", "")

    # Examples
    try:
        examples = (
            entry.get("def", [])[0]
            .get("sseq", "")[0][0][1]
            .get("dt", "")[1][1][0]
            .get("t", "")
        )
        # remove any format specifiers
        examples = sub(r"\{[^}]*\}", "", examples)
    except (AttributeError, IndexError):
        examples = ""

    # inflections
    inflections = ""
    for elem in entry.get("ins", []):
        connector = elem.get("il", None)
        if connector:
            inflections += " " + connector + " "
        else:
            inflections += ", "
        form = elem.get("if", None)
        if form:
            inflections += form.replace("*", "")
    inflections = inflections.split(", ")
    inflections.remove("")

    # Group all information
    word_info = {
        "word": word,
        "part_of_speech": entry.get("fl", "N/A"),
        "definition": definitions,
        "examples": examples,
        "pronunciation": pronunciation,
        "inflections": inflections,
    }
    return word_info


def url(dict, word):
    match dict:
        case "mw":
            return dictionary_base_url + word + "?key=" + dict_api_key
        case "api":
            return "https://api.dictionaryapi.dev/api/v2/entries/en/" + word
        case "linguee":
            return f"http://127.0.0.1:8000/api/v2/translations?query={word}&src=en&dst=de&guess_direction=false&follow_corrections=always"


def get_word_info(word):
    parts_of_speech = [
        "noun",
        "verb",
        "adjective",
        "adverb",
        "pronoun",
        "preposition",
        "conjunction",
    ]

    result = []

    try:
        data = request(url("mw", word))
    except ValueError as e:
        print("ValueError: ", e)
        print("Request failed.")
        return None
    print("Successfully completed request.\n")
    for pos in parts_of_speech:
        # requesting data
        print(f'Looking up "{word}" as a {pos}', end="")

        # processing data
        try:
            info = process_mw(data, word, pos=pos)
        except ValueError as e:
            print("\nValueError: ", e)
            return None
        if isinstance(info, str):
            print(" -> No dictionary entry found.")
            continue
        if info is None:
            continue
        if not isinstance(info, dict):
            raise ValueError("Unknown return type of process_data()")
        result.append(info)
        print(" -> Success")
    return result


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
    try:
        forms = word["forms"]
        line.append("**Forms**: " + ", ".join(forms))
    except KeyError:
        pass
    try:
        line.append(">**Pronunciation**: " + word["phonetic"])
    except KeyError:
        pass
    try:
        link = word["audio_british"]
        audio_lin_be = f'<audio controls><source src="{link}" type="audio/mpeg">Unsupported.</audio>'
        line.append(">**Audio**: " + audio_lin_be)
    except KeyError:
        pass

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
    info["word"] = word
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
            defi = sub(r"\(.*?\)", "", defi).strip()
            info["definition"].append(defi)
    return info


def merge(data1, data2, pos):
    master = {"pos": pos}
    for key, value in data1.items():
        master[key] = value
        # add_to_master(master, (key, value))
    for key, value in data2.items():
        master[key] = value
        # add_to_master(master, (key, value))
    if master["definition"] != []:
        return master
    return None


def main():
    words = get_words(words_per_execution)
    parts_of_speech = [
        "noun",
        "verb",
        "adjective",
        "adverb",
        "pronoun",
        "preposition",
        "conjunction",
    ]
    flashcards = []
    for word in words:
        delay = 0
        if delay != 0:
            print(f"Waiting for {delay} seconds.")
        sleep(delay)
        lin_data = request(url("linguee", word))
        api_data = request(url("api", word))
        if not lin_data or not api_data:
            print(f'Failed to retrieve information for "{word}" -> Skipped.')
            continue
        for pos in parts_of_speech:
            lin_info = process_linguee(lin_data, word, pos)
            api_info = process_dictapi(api_data, word, pos)
            info = merge(lin_info, api_info, pos)
            if info:
                flashcards.append(format_to_flashcard(info))
    checkout(flashcards)


main()
proc.send_signal(signal.SIGINT)  # send SIGINT to stop uvicorn gracefully
proc.wait()
