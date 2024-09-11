import json
import sys
import requests


# Example JSON data

url = 'https://linguee-api.fly.dev/api/v2/translations?query=to%20toil&src=en&dst=de&guess_direction=false&follow_corrections=always'
res = requests.get(url)
print(res)

json_data = res.text
print(json_data, type(json_data))
# Parse JSON data
data = json.loads(json_data)

translated_pos = []

# Extract useful information
for entry in data:
    word = entry.get('text', 'N/A')
    pos = entry.get('pos', 'N/A')
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
        if trans_pos.split(',')[0] != pos.split(',')[0]:
            print(f'error: trans_pos != pos | trans_pos = {trans_pos}, pos = {pos}')
            continue # cant translate verb to noun
        translations.append(trans_word)
        
        # Extract and print example sentences
        for example in translation.get('examples', []):
            src_examples.append(example.get('src', 'No source example'))
            dst_examples.append(example.get('dst', 'No destination example'))

    # print(word, translations, src_examples, dst_examples)
    # Pretty print
    #
    print('-'*30)
    print('English Word: ', word, ': ', (src_examples))
    print('German Word: ', (translations), ':', (dst_examples))
    print('-'*30)
