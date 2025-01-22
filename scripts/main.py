from time import sleep
import requests


def call(url, debug=False):
    while True:
        try:
            res = requests.get(url)
            if res.status_code == 200:
                if debug:
                    print(f"Request succeeded for url: {url}.")
                return res.json()
            else:
                print(f"API request failed with status {res.status_code} for url: {url}.\nRetrying in 5 seconds...")
                sleep(5)
        except requests.exceptions.RequestException as e:
            print(f"Request failed: {e}. Retrying in 5 seconds...")
            sleep(5)


def get_linguee_data(word, pos):
    repl = {'v': 'verb', 'n': 'noun'}
    if pos in repl.keys():
        pos = repl[pos]
    url = f'https://linguee-api.fly.dev/api/v2/translations?query={word}&src=en&dst=de&guess_direction=false&follow_corrections=always'
    data = [data for data in call(url) if data['pos'].startswith(pos)][0]
    text = data['text']
    translations = [(t['text'], t['examples']) for t in data['translations']]
    forms = data['forms']
    translation, examples = translations[0]
    return translation, examples, forms


def get_datamuse_data(word, pos):
    url = f'https://api.datamuse.com/words?sp={word}&md=d+p+r+f'
    data = [data for data in call(url) if pos in data['tags']][0]
    word = data['word']
    frequency = [float(c[2:]) for c in data['tags'] if c.startswith('f:')][0]
    definitions = [defi.split('\t')[1].strip() for defi in data['defs'] if defi.startswith(f"{pos}\t")]
    definitions = [defi for defi in definitions if not defi.startswith('(obsolete)')]
    return frequency, definitions[0]


def get_synonyms(word, max: int = 5):
    url = f'https://api.datamuse.com/words?rel_syn={word}&md=f&max={max}'
    api_data = call(url)
    return [data['word'] for data in api_data]


def fetch_words():
    with open('oxford5000_C1.txt', 'r') as f:
        for data in f.read().split('. '):
            word, pos = data.split()
            yield word, pos


for word, pos in fetch_words():
    translation, examples, forms = get_linguee_data(word, pos)
    frequency, definition = get_datamuse_data(word, pos)
    synonyms = get_synonyms(word)

    c = "\n\t"
    example_strings = [f'{example["dst"]} <-> {example["src"]}' for example in examples]
    print(
        f"Word: {word} ({pos})\n"
        f"German translations: {translation}\n"
        f"German examples: " + ("None" if not example_strings else f"\n\t{c.join(example_strings)}") + "\n"
        f"Forms: {'None' if not forms else ', '.join(forms)}\n"
        f"Occurrence among one million words: {frequency}\n"
        f"Definition: {definition}\n"
        f"Synonyms: {'None' if not synonyms else ', '.join(synonyms)}\n"
    )
    sleep(0.1)