import requests
from bs4 import BeautifulSoup
import os
import re

def scrape_website(url, depth=1, output_dir='output'):
    # Create the output directory if it doesn't exist
    os.makedirs(output_dir, exist_ok=True)

    # Get the initial web page content
    response = requests.get(url)
    soup = BeautifulSoup(response.content, 'html.parser')

    # Filter the filename to remove invalid characters
    filename = re.sub(r'[^\w\-_\. ]', '_', url.replace("https://", "").replace("/", "_")) + ".html"
    filepath = os.path.join(output_dir, filename)

    # Save the initial web page content as an HTML file
    with open(filepath, 'w', encoding='utf-8') as file:
        file.write(soup.prettify())
    print(f'Saved: {filepath}')

    # Follow the links on the current page, if the depth is greater than 0
    if depth > 0:
        for link in soup.find_all('a'):
            href = link.get('href')
            if href and href.startswith('http'):
                scrape_website(href, depth - 1, output_dir)

if __name__ == '__main__':
    url = input('Enter the URL to scrape: ')
    outdir = 'scraped_pages'
    depth = int(input('Enter the depth (number of links to follow): '))
    scrape_website(url, depth, outdir)
