import requests

api_root = "https://linguee-api.fly.dev/api/v2"
resp = requests.get(f"{api_root}/translations", params={"query": "house", "src": "en", "dst": "de"})
for lemma in resp.json():
    for translation in lemma['translations']:
        print(f"{lemma['text']} -> {translation['text']}")
