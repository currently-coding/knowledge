# WordInfo class
from typing import List, Optional
from dataclasses import dataclass, field

# Local server
from signal import SIGINT
from subprocess import DEVNULL, Popen

# Requesting webdata
from time import sleep
from random import randint
from requests import ConnectionError, get

# Read arguments
from sys import argv

# API key
from dotenv import load_dotenv
from os import getenv

# String cleaning
from re import sub

# get API key for Merriam-Webster
load_dotenv()
api_key = getenv("API_KEY")
if api_key:
    use_mw = True
else:
    use_mw = False

# Files
in_filepath = "wordlist.md"
out_filepath = "vocabulary.md"

if len(argv) != 2:
    print(
        f"Exiting...\nIncorrect number of arguments. Expected: 1, Received: {len(argv) - 1}."
    )
    exit("Usage: python vocabulary.py <num_new_flashcards>")
else:
    words_per_execution = int(argv[1])

# if server starts succesfully this will change to localhost
lin_base_url = "https://linguee-api.fly.dev"


@dataclass
class WordInfo:
    word: str
    pos: str
    definitions_api: List[str] = field(default_factory=list)
    definitions_mw: List[str] = field(default_factory=list)
    examples: Optional[List[str]] = None
    translations: List[str] = field(default_factory=list)
    forms: Optional[str] = None
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
        example = sub(r"\{[^}]+\}", "", example)  # remove formatting from mw
        self.examples.append(example)

    def add_translation(self, translation):
        self.translations.append(translation)

    def add_forms(self, forms):
        if not self.forms:
            self.forms = ""
        if len(forms) >= 2:
            forms = ", ".join(forms)
            forms = forms.split(") (")
            if len(forms) > 1:
                forms[0] = "(" + forms[0]
                forms[-1] = forms[-1] + ")"
                forms = ") (".join(forms)
                if forms.startswith("("):
                    forms = forms[1:]
                    forms = forms.replace(")", "", 1)
            else:
                forms = ") (".join(forms)
            self.forms = forms

    def add_audio(self, key, value):
        if not self.audio:
            self.audio = {}
        self.audio[key] = value

    def add_phonetic(self, phonetic):
        self.pronunciation = phonetic

    def to_flashcard(self) -> str:
        flashcard = []
        if use_mw:
            definition = self.definitions_mw[:3]
        else:
            definition = self.definitions_api[:3]
        if len(definition) == 0:
            print(
                f'\nError: Skipping flashcard for "{self.word}" as there was no definition found.'
            )
            return ""
        # Question
        flashcard.append(">[!question]+ Word")
        for translation in self.translations[:3]:
            flashcard.append(">- " + translation)
        flashcard.append(">")
        flashcard.append(">>[!tip]+ Definition")
        for defi in definition[:3]:
            flashcard.append(">>- " + defi)
        # --------
        flashcard.append(self.separator)
        # Answer
        if self.pos == "verb":
            word = "to " + self.word
        else:
            word = self.word
        flashcard.append(">[!vocab]+ " + word + "(" + self.pos + ")")
        flashcard.append(">**Translations**: " + ", ".join(self.translations[:3]))
        if self.forms:
            flashcard.append(">**Forms**: " + self.forms)
        if self.pronunciation:
            flashcard.append(">**Pronunciation**: " + self.pronunciation)
        if self.audio:
            for key, value in self.audio.items():
                value = f'<audio controls><source src={value} type="audio/mpeg">Unsupported.</audio>'
                flashcard.append(">**Audio " + key + "**: " + value)
        if self.examples:
            flashcard.append(">>[!Example]+ Examples")
            for example in self.examples:
                flashcard.append(">>- " + example)
        # ------
        return "\n".join(flashcard) + "\n"


# start server
def start_server():
    """
    Starts the local Linguee API server using Uvicorn.
    Reassigns `lin_base_url` to localhost.

    Returns:
        subprocess.Popen: Process object for the server.
    """
    global lin_base_url
    try:
        print("Starting up server...", end=" ")
        proc = Popen(
            ["uvicorn", "linguee_api.api:app"],
            stdout=DEVNULL,
            stderr=DEVNULL,
        )
        # wait for server to start
        lin_base_url = "http://127.0.0.1:8000"
        for _ in range(20):
            try:
                get(lin_base_url)
                print("-> Success")
                break
            except ConnectionError:
                sleep(0.2)
        return proc
    except (FileNotFoundError, PermissionError, OSError):
        print("-> Failed.\n\t=> Defaulting to https://www.linguee-api.fly.dev/")


def stop_server(server):
    """
    Stops the running Linguee API server process gracefully using SIGINT.

    Args:
        server (subprocess.Popen): Process object returned by `start_server`.
    """
    if not server:
        return
    try:
        print("Shutting down server...", end=" ")
        server.send_signal(SIGINT)  # send SIGINT to stop uvicorn gracefully
        server.wait()
        print("-> Success")
    except (ValueError, AttributeError, ProcessLookupError, ValueError, OSError) as e:
        print("-> Failed.\n", e)


def request(url):
    """
    Sends a GET request to the given URL with retry on failure.
    Handles 404 as a signal for missing data.

    Args:
        url (str): The URL to query.

    Returns:
        dict or None: Parsed JSON response or None if 404.
    """
    while True:
        print(f"Trying to reach {url}", end=" ")
        try:
            response = get(url)
        except ConnectionError:
            print("-> Connection failed. Retrying in 5 seconds.")
            sleep(5)
            continue
        if response.status_code == 404:
            return None
        if response.status_code == 200:
            print("-> Success")
            break
        print(f"-> Request failed: Status Code <{response.status_code}>.")
        sleep(5)
    try:
        return response.json()
    except ValueError as e:
        print("-> Failed.\nFailed to parse JSON:", e)
        print("URL: ", url)
        print("DATA: ", response.text)
        raise e


def get_chosen_entry(data, pos):
    """
    Chooses the dictionary entry with the matching part of speech.

    Args:
        data (list): Merriam-Webster API result list.
        pos (str): Desired part of speech.

    Returns:
        dict or None: Entry with matching POS or None.
    """
    # only use the most popular pos
    # this pos is set by `process_linguee`
    for entry in data:
        if entry.get("fl", None) == pos:
            return entry
    return None


def process_mw(result: WordInfo, data, word, pos):
    """
    Parses Merriam-Webster data for definitions and examples.

    Args:
        result (WordInfo): WordInfo object to populate.
        data (list): MW API JSON.
        word (str): The target word.
        pos (str): Desired part of speech.
    """
    entry = get_chosen_entry(data, pos)
    if not entry:
        print(f"-> No Entry was found for the {pos} {word}.")
        return
    # FIX: also removes skips wrong words
    if word not in entry.get("meta", {}).get("id", ""):
        print(f"-> No Entry was found for the {pos} {word}.")
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
                    if dt_item[0] == "vis":
                        for vis in dt_item[1]:
                            example = vis.get("t", None)
                            if example:
                                result.add_example(example)


def process_dictapi(result: WordInfo, data, word, pos):
    """
    Parses Free Dictionary API data for phonetics and definitions.

    Args:
        result (WordInfo): WordInfo object to populate.
        data (list): API JSON result.
        word (str): The queried word.
        pos (str): Target part of speech.
    """
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
            result.add_definition("api", defi)


def process_linguee(data, word) -> WordInfo:
    """
    Parses Linguee data and populates WordInfo with translations, forms, examples, and audio.

    Args:
        data (list): JSON result from Linguee.
        word (str): The queried word.

    Returns:
        WordInfo: Populated object.
    """
    if len(data) < 1:
        raise ValueError("Unknown word. No entry was found")
    entry = data[0]
    pos = entry.get("pos", None)
    word = entry.get("text", None)
    if not word or not pos:
        raise ValueError("Unknown word. No entry was found")
    result = WordInfo(word=word, pos=pos)
    audios = entry.get("audio_links", [])
    if not audios:
        audios = []
    for audio in audios:
        to_remove = "https://www.linguee.com/mp3/"
        if audio.get("lang", "") == "British English":
            link = audio.get("url")
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
    """
    Returns the appropriate API URL for the given dictionary and word.

    Args:
        dictionary (str): One of 'api', 'linguee', or 'mw'.
        word (str): Word to look up.

    Returns:
        str: Fully qualified API URL.
    """
    match dictionary:
        case "api":
            return "https://api.dictionaryapi.dev/api/v2/entries/en/" + word
        case "linguee":
            lin_url = f"{lin_base_url}/api/v2/translations?query={word}&src=en&dst=de&guess_direction=false&follow_corrections=always"
            return lin_url
        case "mw":
            return f"https://dictionaryapi.com/api/v3/references/collegiate/json/{word}?key={api_key}"


def checkout(lines):
    """
    Appends generated flashcards to the output file and removes used words from the input file.

    Args:
        lines (list[str]): Flashcard strings.
    """
    print("\n")
    with open(out_filepath, "a") as f:
        print(f"Writing {len(lines)} flashcards to output file...", end="")
        for line in lines:
            f.write(line)
            f.write("\n")
        print(" -> Success")

    print(f"Deleting {words_per_execution} words from input file...", end="")
    with open(in_filepath, "r") as fin:
        remaining = fin.readlines()[words_per_execution:]

    with open(in_filepath, "w") as fout:
        fout.writelines(remaining)
    print(" -> Success")


def get_words(amount):
    """
    Reads a number of words from the input file.

    Args:
        amount (int): Number of words to read.

    Returns:
        list[str]: List of words.
    """
    print(f"Reading {amount} words from input file...", end="")
    with open(in_filepath, "r") as f:
        words = [next(f).strip() for _ in range(amount)]
    print(" -> Success.")
    return words


def main():
    """
    Main execution logic: retrieves words, queries APIs, processes results,
    writes flashcards, and handles server lifecycle.
    """
    proc = start_server()

    words = get_words(words_per_execution)
    flashcards = []
    for word in words:
        delay_per_request = randint(0, 4)
        if delay_per_request != 0:
            print(f"\nWaiting for {delay_per_request} seconds.\n")
        sleep(delay_per_request)
        print(f"\nLooking up {word}...\n")
        lin_data = request(url("linguee", word))
        api_data = request(url("api", word))
        if use_mw:
            mw_data = request(url("mw", word))
        else:
            mw_data = None
        # lin data is needed and one of api/mw for the definition
        if not lin_data or (not api_data and mw_data):
            print(f'Failed to retrieve information for "{word}" -> Skipped.')
            continue
        info = process_linguee(lin_data, word)
        process_dictapi(info, api_data, word, info.pos)
        if use_mw:
            process_mw(info, mw_data, word, info.pos)

        flashcard = info.to_flashcard()
        flashcards.append(flashcard)
    # do all permanent file actions
    checkout(flashcards)
    stop_server(proc)


if __name__ == "__main__":
    main()
