

# settings

FILEPATH = 'oxford5000_C1.txt'

# ---


words = []


with open(FILEPATH, 'r') as f:
    content = f.read()
f.close()

content = content.split(".")
print(content)
content = content.split(" ")
print(content)
