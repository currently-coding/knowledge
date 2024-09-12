import json
import sys
from time import sleep
import requests
import os


# ======  Global Settings  =======

src_lang = 'en'
dst_lang = 'de'
guess_direction = False  # guess the translation direction (rather unstable)
follow_correctin = 'always'  # in case of wrong spelling use suggestion

in_file = 'input.txt'
# use path starting at the vault root
out_file = '../00 Karteikarten 1/English/vocabulary.md'

output_with_examples = True
separator = '<->'
amount_of_words_per_execution = 7

# ================================

# Reading the new words
new_words: list[] = []

with open(in_file, 'r') as f_in, open(in_file + '.tmp', 'w') as f_tmp:
    # read first few words from original file
    for word in f_in.readlines(amount_of_words_per_execution):
        new_words.append(word)

    # write remaining words to new file
    for line in f_in:
        f_tmp.write(line)
f_tmp.close()
f_in.close()

# replace original file with new file -> deleted used words
os.replace(in_file + '.tmp', in_file)


new_entries: list[] = []

for word in new_words:
    query = word

    status_code = -1
    count = 0  # for timeouts after unsuccessful request

    while status_code != 200:
        # API Call: Linguee API
        url = f'https://linguee-api.fly.dev/api/v2/translations?query={query}&src={src_lang}&dst={
            dst_lang}&guess_direction={guess_direction}&follow_corrections={follow_corrections}'
        res = requests.get(url)
        print("Server: ", res)
        status_code = res.status_code
        if count > 0:
            print(f"Request failed.\nTrying again in less than {
                  count*7} seconds...")
        sleep(count*7+0.001)  # 0sec timeout on first try
        count += 1

    json_data = res.text

    # Parse JSON data
    data = json.loads(json_data)

    translated_pos = []

    # Get translations
    print(data)
    for entry in data:
        pos = entry.get('pos', 'N/A').split(',')[0]
        to = "to " if pos == "verb" else ""
        word = to + entry.get('text', 'N/A')
        if pos in translated_pos:
            continue  # wanted word has already been translated
        translated_pos.append(pos)

        # Extract translations
        translations = []
        src_examples = []
        dst_examples = []

        for translation in entry.get('translations', []):
            trans_word = translation.get('text', 'N/A')
            trans_pos = translation.get('pos', 'N/A')
            if pos not in trans_pos:
                continue  # cant translate verb to noun
            translations.append(trans_word)

            # Extract and print example sentences
            for example in translation.get('examples', []):
                src_examples.append(example.get('src', 'No source example'))
                dst_examples.append(example.get(
                    'dst', 'No destination example'))

        # Lists to strings
        src_examples = "\'" + "\', \'".join(src_examples) + "\'"
        dst_examples = "\'" + "\', \'".join(dst_examples) + "\'"
        translations = "\'" + "\', \'".join(translations) + "\'"

        if not output_with_examples:
            src_examples = ""  # overwrite examples
            dst_examples = ""
        print(pos)
        output = word + "(" + pos + ")" + " (" + (src_examples) + ") " + \
            separator + " " + translations + " (" + dst_examples + ")\n"
        new_entries.append(output)


with open(out_file, 'a') as f_out:
    for entry in new_entries:
        f_out.write(entry)
f_out.close()

print(new_entries)ions = 'always'
