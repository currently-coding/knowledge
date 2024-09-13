import json
from time import sleep
import requests
import os


# ======  Global Settings  =======

src_lang = 'en'
dst_lang = 'de'
guess_direction = False
follow_corrections = 'always'

in_file = 'words_out.md'
out_file = '../00 Karteikarten 1/English/vocabulary.md'

output_with_examples = (True, False)
separator = '<->'
amount_of_words_per_execution = 5

# ================================

# Function to read words from the file
def read_words(file, amount):
    new_words = []
    try:
        with open(file, 'r') as f_in, open(file + '.tmp', 'w') as f_tmp:
            words = [next(f_in).strip() for _ in range(amount)]
            new_words.extend(words)
            for line in f_in:
                f_tmp.write(line)
        return new_words
    except Exception as e:
        print(f"Error reading file: {e}")
        return []

# Function to replace the old file with the new one
def replace_file(old_file, new_file):
    try:
        os.replace(old_file, new_file)
    except Exception as e:
        print(f"Error replacing file: {e}")

# Function to call the Linguee API
def call_api(word, src_lang, dst_lang, guess_direction, follow_corrections):
    url = f'https://linguee-api.fly.dev/api/v2/translations?query={word}&src={src_lang}&dst={dst_lang}&guess_direction={guess_direction}&follow_corrections={follow_corrections}'
    while True:
        try:
            res = requests.get(url)
            if res.status_code == 200:
                print("Request succeded.")
                return res.json()
            else:
                print(f"API request failed with status {res.status_code}. Retrying in 5 seconds...")
                sleep(5)
        except requests.exceptions.RequestException as e:
            print(f"Request failed: {e}. Retrying in 5 seconds...")
            sleep(5)

# Function to write new entries to the output file
def write_output(file, entries):
    try:
        with open(file, 'a') as f_out:
            f_out.writelines(entries)
    except Exception as e:
        print(f"Error writing to file: {e}")

# Function to process and format translation data
def process_translations(data, output_with_examples):
    new_entries = []
    for entry in data:
        pos = entry.get('pos', 'N/A').split(',')[0]
        word = f"to {entry.get('text', 'N/A')}" if pos == "verb" else entry.get('text', 'N/A')
        
        translations = [t['text'] for t in entry.get('translations', []) if pos in t['pos']]
        src_examples = [e['src'] for t in entry.get('translations', []) for e in t.get('examples', [])]
        dst_examples = [e['dst'] for t in entry.get('translations', []) for e in t.get('examples', [])]

        if not output_with_examples[0]:
            src_examples = []
        if not output_with_examples[1]:
            dst_examples = []

        entry_str = f"{word}({pos}) ({', '.join(src_examples)}) {separator} {', '.join(translations)} ({', '.join(dst_examples)})\n"
        new_entries.append(entry_str)
    return new_entries


# Main Execution Flow
new_words = read_words(in_file, amount_of_words_per_execution)
new_entries = []
total = len(new_words)
done = 0

for word in new_words:
    data = call_api(word, src_lang, dst_lang, guess_direction, follow_corrections)
    done += 1
    print(done , '/' , total , 'requests done')

    new_entries.extend(process_translations(data, output_with_examples))

print('Requests complete. Removing words from file...')
replace_file(in_file + '.tmp', in_file)

print('Writing data to output file...')
write_output(out_file, new_entries)

print('Execution successful. Exiting...')
