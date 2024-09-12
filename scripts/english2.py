import os
import requests
from time import sleep
import sys
import json

for word in new_words:
    query = word

    # API Call: Linguee API
    url = f'https://linguee-apdirection={
        guess_direction}&follow_corrections={follow_corrections}'
    res = requests.get(url)

    if res.status_code != 200:  # 200 = OK
        sys.exit(f"Server currently unavailable. Please come back later. Status: {
                 res.status_code}")

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
print(new_entries)
