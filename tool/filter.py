import os
import re

def filter_ethiopic_text(input_dir, output_dir):
    # Create the output directory if it doesn't exist
    os.makedirs(output_dir, exist_ok=True)

    # Iterate over the files in the input directory
    for filename in os.listdir(input_dir):
        # Check if the file is a regular file (not a directory)
        if os.path.isfile(os.path.join(input_dir, filename)):
            # Open the input file and read its contents
            with open(os.path.join(input_dir, filename), 'r', encoding='utf-8') as file:
                content = file.read()

            # Filter out non-Ethiopic characters and separate with spaces
            filtered_content = ' '.join(re.findall(r'[\u1200-\u137F]+', content))

            # Save the filtered content to a new file in the output directory
            output_filename = os.path.splitext(filename)[0] + '_filtered.txt'
            output_path = os.path.join(output_dir, output_filename)
            with open(output_path, 'w', encoding='utf-8') as output_file:
                output_file.write(filtered_content)
            print(f'Saved: {output_path}')

if __name__ == '__main__':
    input_dir = input('Enter the input directory path: ')
    output_dir = "filtered_data"
    filter_ethiopic_text(input_dir, output_dir)
