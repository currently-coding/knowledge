import json
import sys
import requests


# Global Settings

src_lang = 'en'
dst_lang = 'de'
guess_direction = False # guess the translation direction (rather unstable)
follow_corrections = 'always' # in case of wrong spelling

in_file = 'input.txt'
out_file = 'output.txt'

output_with_examples = False
separator = '<->'
amount_of_words_per_execution = 10



# Reading the new words

new_words = []

with open(in_file, 'r') as f_in:
    for word in f_in.readlines(amount_of_words_per_execution):
        new_words.append(word)
f_in.close()

new_entries = []

for word in new_words:
    query = word

    url = f'https://linguee-api.fly.dev/api/v2/translations?query={query}&src={src_lang}&dst={dst_lang}&guess_direction={guess_direction}&follow_corrections={follow_corrections}'
    res = requests.get(url)
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
            print('Avoided Incorrect Word')
            continue # wanted word has already been translated
        translated_pos.append(pos)
        
        # Extract translations
        translations = []
        src_examples = []
        dst_examples = []

        for translation in entry.get('translations', []):
            trans_word = translation.get('text', 'N/A')
            trans_pos = translation.get('pos', 'N/A')
            if pos not in trans_pos:
                print('Avoided Incorrect Translation!')
                continue # cant translate verb to noun
            translations.append(trans_word)
          
            # Extract and print example sentences
            for example in translation.get('examples', []):
                src_examples.append(example.get('src', 'No source example'))
                dst_examples.append(example.get('dst', 'No destination example'))


        # Lists to strings
        src_examples = ", ".join(src_examples)
        dst_examples = ", ".join(dst_examples)
        translations = ", ".join(translations)

        if not output_with_examples:
            src_examples = "" # overwrite examples
            dst_examples = ""
        output = word + " " + (src_examples) + " " + separator + " " + translations + " " + dst_examples + "\n"
        new_entries.append(output)


with open(out_file, 'a') as f_out:
    for entry in new_entries:
        f_out.write(entry)
f_out.close()

print(new_entries)
