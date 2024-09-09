import requests

# Example list of words
english_words = ["book", "apple", "tree"]

# Your API key
api_key = 'nstciea54ea4863iesthao'

# Function to query the PONS API
def get_translation_and_example(word, api_key):
    url = f"https://api.pons.com/v1/dictionary?q={word}&l=ende"  # 'ende' for English-German
    headers = {"X-Secret": api_key}  # Passing the API key in the header
    
    response = requests.get(url, headers=headers)
    
    if response.status_code == 200:
        data = response.json()
        if data:  # Check if data was returned
            try:
                # Extract the first German translation and the first English example sentence
                german_translation = data[0]['hits'][0]['roms'][0]['arabs'][0]['translations'][0]['target']
                english_example = data[0]['hits'][0]['roms'][0]['arabs'][0]['examples'][0]['source']
                return german_translation, english_example
            except (IndexError, KeyError):
                return "", ""  # Return empty strings if the structure is not found
        else:
            return "", ""  # No translations found
    elif response.status_code == 204:
        print(f"No content found for '{word}'")
        return "", ""
    else:
        print(f"Error: {response.status_code}")
        return "", ""

# Dictionary to hold the English words with German translations and examples
translations_dict = {}

# Populate the dictionary
for word in english_words:
    german_translation, english_example = get_translation_and_example(word, api_key)
    translations_dict[word] = {
        "German": german_translation,
        "Example": english_example
    }

# Output the result
print(translations_dict)

