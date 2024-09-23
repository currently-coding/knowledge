def remove_duplicate_and_next(lines):
    seen = set()  # To track unique lines
    result = []
    skip_next = False  # Flag to skip the next line after a duplicate

    for i, line in enumerate(lines):
        if skip_next:  # If previous line was a duplicate, skip this one
            skip_next = False
            continue

        if line.startswith("<"):  # Ignore lines that start with "<"
            result.append(line)
            continue

        if line in seen:  # If the line is a duplicate
            skip_next = True  # Set the flag to skip the next line
            print("skipping line")
        else:
            seen.add(line)  # Add line to seen set
            result.append(line)  # Add line to result if it's not a duplicate

    return result


# Read input from vocabulary.md
with open("vocabulary.md", "r") as file:
    lines = file.readlines()  # Read all lines from the file

# Process the lines to remove duplicates and the line beneath them
filtered_lines = remove_duplicate_and_next(lines)

# Write the result back to the file (or a new file)
with open("filtered_vocabulary.md", "w") as output_file:
    output_file.writelines(filtered_lines)
