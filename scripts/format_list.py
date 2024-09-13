# Load the content of the file, clean it and extract only the words
file_path = 'oxford5000_C1.txt'
output_file_path = 'words_out.md'

# Read the file content
with open(file_path, 'r') as file:
    content = file.read()
file.close()

items = content.split()

# List of part-of-speech markers to exclude
pos_markers = ['v.', 'adj.', 'n.', 'adv.', 'prep.', 'pron.', 'conj.', 'int.', 'det.', 'n.,', 'v.,']

# Initialize an empty list to store the cleaned words
cleaned_words = []

# Loop through the items and only keep actual words (skip POS markers)
for i in range(0, len(items)):
    if items[i] not in pos_markers:
        cleaned_words.append(items[i])

# Join the cleaned words with new lines
output = '\n'.join(cleaned_words)

# Save the result to a file or print it
print(output)
# Write the cleaned words to the file
with open(output_file_path, 'w') as output_file:
    output_file.write(output)
output_file.close()
