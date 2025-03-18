import random

def randomize_lines_from(file_path, start_line):
    with open(file_path, 'r') as file:
        # Process the header lines and store them
        header = [next(file) for _ in range(start_line)]  # Only read up to start_line
        
        # Read the remaining lines to be shuffled
        to_randomize = file.readlines()  # Read remaining lines only

    random.shuffle(to_randomize)  # Shuffle the lines starting from start_line

    with open(file_path, 'w') as file:
        file.writelines(header)  # Write header back to the file
        file.writelines(to_randomize)  # Write shuffled lines back to the file

# Example usage:
randomize_lines_from('wordlist.md', 7)

