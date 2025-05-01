import signal
from dataclasses import dataclass, field
from typing import List, Optional
import subprocess
from re import sub
from time import sleep
from requests import ConnectionError, get
from random import randint

in_filepath = "wordlist.md"
out_filepath = "vocabulary.md"
words_per_execution = 10
max_num_translations = 3

# vars
audio_british = "audio_british"
audio_american = "audio_american"

lin_base_url = "https://linguee-api.fly.dev"


@dataclass
class WordInfo:
    word: str
    pos: str
    definitions_api: List[str] = field(default_factory=list)
    definitions_mw: List[str] = field(default_factory=list)
    examples: Optional[List[str]] = None
    translations: List[str] = field(default_factory=list)
    forms: Optional[List[str]] = None
    pronunciation: Optional[str] = None
    audio: Optional[dict[str, str]] = None
    separator: str = "?"
    max: int = 3

    def add_definition(self, source, definition):
        match source:
            case "api":
                self.definitions_api.append(definition)
            case "mw":
                self.definitions_mw.append(definition)

    def add_example(self, example):
        if not self.examples:
            self.examples = []
        example = sub(r"\{[^}]+\}", "", example)
        # example.replace("{wi}", "")
        # example.replace("{/wi}", "")
        self.examples.append(example)

    def add_translation(self, translation):
        self.translations.append(translation)

    def add_forms(self, forms):
        if not self.forms:
            self.forms = []
        if len(forms) >= 2:
            self.forms.append(forms)

    def add_audio(self, key, value):
        if not self.audio:
            self.audio = {}
        self.audio[key] = value

    def add_phonetic(self, phonetic):
        self.pronunciation = phonetic

    def to_flashcard(self) -> str:
        flashcard = []
        definition = (
            ", ".join(self.definitions_mw[:3])
            + ", "
            + ", ".join(self.definitions_api[:3])
        )
        flashcard.append(definition)
        flashcard.append(self.separator)
        flashcard.append(">[!vocab] " + self.word + "(" + self.pos + ")")
        flashcard.append(">**Translations**: " + ", ".join(self.translations[:3]))
        if self.forms:
            print("forms: ", self.forms)
            flashcard.append(">**Forms**: " + ", ".join(self.forms[0]))
        if self.pronunciation:
            flashcard.append(">**Pronunciation**: " + self.pronunciation)
        if self.audio:
            for key, value in self.audio.items():
                value = f'<audio controls><source src={value} type="audio/mpeg">Unsupported.</audio>'
                flashcard.append(">**Audio " + key + "**: " + value)
        if self.examples:
            flashcard.append(">>[!Example] Examples")
            for example in self.examples:
                flashcard.append(">>- " + example)
        return "\n".join(flashcard) + "\n"


# start server
def start_server():
    proc = subprocess.Popen(
        ["uvicorn", "linguee_api.api:app"],
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
    )
    # wait for server to start
    lin_base_url = "http://127.0.0.1:8000"
    for _ in range(20):
        try:
            get(lin_base_url)
            print("Server is running...")
            break
        except ConnectionError:
            sleep(0.2)
    return proc


def stop_server(server):
    if not server:
        return
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


def process_mw(result: WordInfo, data, word, pos):
    entry = get_chosen_entry(data, pos)
    if not entry:
        return
    for definition in entry.get("shortdef", []):
        if definition and definition != "":
            result.add_definition("mw", definition)
    for def_block in entry.get("def", []):
        for sseq in def_block.get("sseq", []):
            for sense_group in sseq:
                if type(sense_group) is not dict:
                    continue
                sense_data = sense_group[-1].get(
                    "sense", sense_group[-1]
                )  # handle both "bs" and "sense"

                # Collect definition text and usage examples
                for dt_item in sense_data.get("dt", []):
                    if dt_item[0] == "text":
                        # result.add_definition("mw", dt_item[1])
                        pass
                    elif dt_item[0] == "vis":
                        for vis in dt_item[1]:
                            example = vis.get("t", None)
                            if example:
                                result.add_example(example)


def process_linguee(data, word) -> WordInfo:
    if len(data) < 1:
        raise ValueError("Unknown word. No entry was found")
    entry = data[0]
    pos = entry.get("pos", None)
    word = entry.get("text", None)
    if not word or not pos:
        raise ValueError("Unknown word. No entry was found")
    result = WordInfo(word=word, pos=pos)
    # audio file
    audios = entry.get("audio_links", [])
    if not audios:
        audios = []
    for audio in audios:
        to_remove = "https://www.linguee.com/mp3/"
        if audio.get("lang", "") == "British English":
            link = audio.get("url")
            print("contains: ", to_remove in link)
            if to_remove in link:
                link = link.replace(to_remove, "")
            result.add_audio("british", link)
        elif audio.get("lang", "") == "American English":
            link = audio.get("url")
            if to_remove in link:
                link = link.replace(to_remove, "")
            result.add_audio("american", link)

    forms = entry.get("forms", [])
    result.add_forms(forms)

    # translation
    for trans in entry.get("translations", []):
        translation = trans.get("text", None)
        if translation:
            result.add_translation(translation)
        for ex in trans.get("examples", []):
            example = ex.get("src", None)
            if example:
                result.add_example(example)
    return result


def url(dictionary, word):
    match dictionary:
        case "api":
            return "https://api.dictionaryapi.dev/api/v2/entries/en/" + word
        case "linguee":
            lin_url = f"{lin_base_url}/api/v2/translations?query={word}&src=en&dst=de&guess_direction=false&follow_corrections=always"
            return lin_url
        case "mw":
            return f"https://dictionaryapi.com/api/v3/references/collegiate/json/{word}?key=51624bf2-914f-4dee-b757-83d6a2c67fb2"


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
    line.append(">[!vocab]+ " + word["word"] + "(" + word["pos"] + ")")
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


def process_dictapi(result: WordInfo, data, word, pos):
    for entry in data:
        meaning_entry = {}
        for m in entry.get("meanings", []):
            if m.get("partOfSpeech", "") == pos:
                meaning_entry = m
                break

        phonetic = entry.get("phonetic", None)
        if phonetic:
            result.add_phonetic(phonetic)
        for definition in meaning_entry.get("definitions", []):
            defi = definition.get("definition", None)
            if not defi or defi == "":
                continue
            # defi = sub(r"\([^\s]*?\)", "", defi).strip()
            result.add_definition("api", defi)


def merge(data1, data2, pos):
    master = {"pos": pos}

    keys = set(data1) | set(data2)
    for key in keys:
        val1 = data1.get(key)
        val2 = data2.get(key)

        if key in data1 and key in data2:
            if val1 == val2:
                master[key] = val1
            else:
                # Combine into list, avoiding nested lists and duplicates
                combined = []
                if isinstance(val1, list):
                    combined.extend(val1)
                else:
                    combined.append(val1)
                if isinstance(val2, list):
                    combined.extend(val2)
                else:
                    combined.append(val2)
                # Remove duplicates, preserve order
                seen = set()
                for x in combined:
                    seen.add(str(x))
                master[key] = list(seen)
        else:
            master[key] = val1 if key in data1 else val2

    return master if master.get("definition") else None


def main():
    proc = None
    try:
        proc = start_server()
    except:
        print('Setting up server failed.\nDefaulting to "https://linguee-api.fly.dev"')
        pass

    words = get_words(words_per_execution)
    flashcards = []
    for word in words:
        delay_per_request = randint(1, 5)
        if delay_per_request != 0:
            print(f"Waiting for {delay_per_request} seconds.")
        sleep(delay_per_request)
        lin_data = request(url("linguee", word))
        api_data = request(url("api", word))
        mw_data = request(url("mw", word))
        # lin data is needed and one of api/mw for the definition
        if not lin_data or (not api_data and mw_data):
            print(f'Failed to retrieve information for "{word}" -> Skipped.')
            continue
        info = process_linguee(lin_data, word)
        process_dictapi(info, api_data, word, info.pos)
        process_mw(info, mw_data, word, info.pos)

        # merge data from all sources
        flashcard = info.to_flashcard()
        flashcards.append(flashcard)
    # do all permanent file actions
    checkout(flashcards)
    try:
        stop_server(proc)
    except (
        AttributeError,
        ProcessLookupError,
        ValueError,
        OSError,
        UnboundLocalError,
    ) as e:
        print("Error while trying to shut down server:", e)


if __name__ == "__main__":
    main()
