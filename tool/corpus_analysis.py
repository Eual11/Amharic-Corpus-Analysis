import os
from collections import Counter
from datetime import datetime

def analyze_word_frequencies(input_dir, output_filename):
    # Initialize a dictionary to store the word frequencies
    word_frequencies = {}

    # Iterate over the files in the input directory
    for filename in os.listdir(input_dir):
        # Check if the file is a regular file (not a directory)
        if os.path.isfile(os.path.join(input_dir, filename)):
            # Open the input file and read its contents
            with open(os.path.join(input_dir, filename), 'r', encoding='utf-8') as file:
                content = file.read()

            # Split the content into words and count their frequencies
            words = content.split()
            word_count = Counter(words)

            # Update the word_frequencies dictionary
            word_frequencies.update(word_count)

    # Sort the word_frequencies dictionary by value (frequency) in descending order
    sorted_frequencies = sorted(word_frequencies.items(), key=lambda x: x[1], reverse=True)

    # Get the current date and time
    now = datetime.now()
    timestamp = now.strftime('%Y%m%d_%H%M%S')

    # Construct the output file path
    output_file = f'{output_filename}_{timestamp}.txt'

    # Write the sorted word frequencies to the output file
    with open(output_file, 'w', encoding='utf-8') as file:
        for word, freq in sorted_frequencies:
            file.write(f'{word} {freq}\n')

    print(f'Saved: {output_file}')

if __name__ == '__main__':
    input_dir = input('Enter the input directory path: ')
    output_filename = 'frequency_data'
    analyze_word_frequencies(input_dir, output_filename)
