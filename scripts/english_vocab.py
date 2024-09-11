import requests

# Function to get translations and example sentence from Linguee API
def get_translations_and_examples(word):
    url = f"https://api.linguee.com/api/v2/translation?query={word}&src=en&dst=de"
    response = requests.get(url)
    data = response.json()
    
    translations = []
    examples = []
    
    for entry in data['translations']:
        translations.append(entry['translation'])
        examples.append(entry['example']['de'])  # Example sentence in German
        
    return translations, examples

# Read lines from a file, translate them, and format output
def translate_file(input_file, output_file):
    with open(input_file, 'r') as infile, open(output_file, 'w') as outfile:
        for line in infile:
            line = line.strip()
            if line:
                translations, examples = get_translations_and_examples(line)
                if translations:
                    example_sentence = examples[0] if examples else "No example available"
                    formatted_output = f"{line} <spoiler secure: {example_sentence}> -> {', '.join(translations)}\n"
                    outfile.write(formatted_output)

# Usage
input_file = 'input.txt'
output_file = 'output.txt'
translate_file(input_file, output_file)

