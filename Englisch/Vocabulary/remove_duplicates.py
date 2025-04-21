filepath = "wl3.md"

with open(filepath, "r") as f:
    lines = set(f.readlines())
f.close()
with open(filepath, "w") as f:
    for line in lines:
        f.write(line)
f.close()
