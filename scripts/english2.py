import json
from time import sleep
import requests
import os


# ======  Global Settings  =======

src_lang = 'en'
dst_lang = 'de'
guess_direction = False  # guess the translation direction (rather unstable)
follow_corrections = 'always'  # in case of wrong spelling use suggestion

in_file = 'words_out.md'
# use path starting at the vault root
out_file = '../00 Karteikarten 1/English/vocabulary.md'

# (True, True) => Both langs | (False, False) => No examples
output_with_examples = (True, False)
separator = '<->'
quote = "'"
amount_of_words_per_execution = 5

# ================================

# Reading the new words
new_words = []


with open(in_file, 'r') as f_in, open(in_file + '.tmp', 'w') as f_tmp:
    # read first few words from original file
    words = [next(f_in)[:-1] for _ in range(amount_of_words_per_execution)]


    for word in words:
        new_words.append(word)

    # write remaining words to new file
    for line in f_in:
        f_tmp.write(line)
f_tmp.close()
f_in.close()


new_entries = []
total_requests = len(new_words)
successful_requests = 0


for word in new_words:
    query = word

    status_code = -1
    count = 0  # for timeouts after unsuccessful request

    while status_code != 200:
        # API Call: Linguee API
        print("Calling the API")
        url = f'https://linguee-api.fly.dev/api/v2/translations?query={query}&src={src_lang}&dst={
            dst_lang}&guess_direction={guess_direction}&follow_corrections={follow_corrections}'
        res = requests.get(url)
        status_code = res.status_code
        print('Info: ', status_code) # could refactor into ternary
        if status_code != 200:
            print(f"Request failed.\nTrying again in 5 seconds...")
            sleep(5)  # 0 sec timeout on first try
        else:
            print("Successful request.")
        count += 1

    successful_requests += 1
    print(f'Request {successful_requests}/{total_requests} complete')

    json_data = res.text

    # Parse JSON data
    data = json.loads(json_data)

    translated_pos = []

    # Get translations
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

        if not output_with_examples[0]:
            src_examples = ""
        if not output_with_examples[1]:
            dst_examples = ""

        output = word + "(" + pos + ")" + " (" + (src_examples) + ") " + \
            separator + " " + translations + " (" + dst_examples + ")\n"
        new_entries.append(output)

print('Requests complete.\nRemoving words from file...')

# replace original file with new file -> deleted used words
os.replace(in_file + '.tmp', in_file)

print('Writing data to output file...')

with open(out_file, 'a') as f_out:
    for entry in new_entries:
        f_out.write(entry)
f_out.close()

print('Execution successful. Exiting...')
