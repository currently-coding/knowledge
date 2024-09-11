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

# Remebering old words to avoid duplicates

words = []

with open(out_file, 'r') as f_out:
    for line in f_out.readlines():
        if line[:3] == "to ":
            word = line.split()[:1].join(" ")
        else:
            word = line.split()[0].join()
        words.append(word)
f_out.close()

# Reading the new words

new_words = []

with open(in_file, 'r') as f_in:
    for word in f_in.readlines():
        new_words.append(word)
f_in.close()


for word in new_words:
    query = word

    url = f'https://linguee-api.fly.dev/api/v2/translations?query={query}&src={src_lang}&dst={dst_lang}&guess_direction={guess_direction}&follow_corrections={follow_corrections}'
    res = requests.get(url)
    json_data = res.text
# Parse JSON data
    data = json.loads(json_data)

    translated_pos = []

    count = 0

    # Get translations
    for entry in data:
        # if count > 3: # Most times the fourth result is bad as the first is the noun, the second the verb and the third the adj.
        #     break
        word = entry.get('text', 'N/A')
        pos = entry.get('pos', 'N/A').split(',')[0]
        if pos in translated_pos:
            print('error: pos in translated_pos')
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
                print(f'error: trans_pos != pos | translated_pos = {trans_pos}, original_pos = {pos}')
                continue # cant translate verb to noun
            translations.append(trans_word)
          
            # Extract and print example sentences
            for example in translation.get('examples', []):
                src_examples.append(example.get('src', 'No source example'))
                dst_examples.append(example.get('dst', 'No destination example'))


        # Pretty print
        #
        print('-'*30)
        print('English Word: ', word, ': ', (src_examples), pos)
        print('German Word: ', (translations), ':', (dst_examples), trans_pos)
        print(translated_pos)
        print('-'*30)
