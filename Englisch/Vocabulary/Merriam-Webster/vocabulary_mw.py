from os import getenv
from re import sub
from time import sleep

from requests import get
from dotenv import load_dotenv

load_dotenv()

dict_api_key = getenv("DICT_API_KEY")
in_filepath = "wordlist_mw.md"
out_filepath = "vocabulary_mw.md"
words_per_execution = 2
if not dict_api_key:
    raise ValueError("API key not found. Please set API_KEY in .env file.")


dictionary_base_url = "https://dictionaryapi.com/api/v3/references/collegiate/json/"
thesaurus_base_url = "https://dictionaryapi.com/api/v3/references/thesaurus/json/"


def request(word):
    """requests dictionary entry from merriam-webster-dict"""
    if not word:
        print("Word is empty. Aborting...")
        raise ValueError("Word is empty.")
    url = f"{dictionary_base_url}{word}?key={dict_api_key}"

    response = None
    while not response:
        print(f'Trying to reach url for word "{word}"...')
        response = get(url)
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

    return data


def get_chosen_entry(data, pos):
    # excludes unwanted things e.g. 'stage direction'
    for entry in data:
        if entry.get("fl", None) == pos:
            return entry
    return None


def process_data(data, word, pos, num_definitions=3):
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
        examples = sub(r"\{[^}]*\}", "", examples)  # remove any format specifiers
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
        inflections += elem.get("if", "").replace("*", "")

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
        data = request(word)
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
            info = process_data(data, word, pos=pos)
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


def format_to_flashcard(wordlist):
    separator = "\n?\n"
    lines = []
    for word in wordlist:
        # Example line
        # <definition>
        # >[!]
        if word["part_of_speech"] == "verb":
            word["word"] = "to " + word["word"]
        line = ""
        line += ", ".join(word["definition"])
        line += separator
        line += ">[!info]- " + word["word"] + "(" + word["part_of_speech"] + ")"
        if word["inflections"] != "":
            line += "\n**Inflections**: " + word["word"] + word["inflections"]
        if word["pronunciation"] != "":
            line += "\n**Pronunciation**: " + word["pronunciation"]
        if word["examples"] != "":
            line += "\n**Examples**: " + word["examples"]
        line += "\n"

        lines.append(line)
    return lines


def checkout(lines):
    with open(out_filepath, "a") as f:
        print("Writing to output file...", end="")
        f.write("\n".join(lines) + "\n")  # added newline for separation
        print(" -> Success")

    lines = []

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


def create_flashcard(word):
    data = get_word_info(word)
    lines = format_to_flashcard(data)
    return lines


def main():
    words = get_words(words_per_execution)
    flashcards = []
    for word in words:
        print(f"Processing word {word}...")
        lines = create_flashcard(word)
        for line in lines:
            flashcards.append(line)
        print(f"Processed word {word} successfully.")
        print("---\n")
    checkout(flashcards)


main()
