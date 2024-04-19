
'''
This script automates the task of crawling amharic words with their 
respective frequency in web corpuses

Output Example 

=====================
ነው 260338
ላይ 174891
ውስጥ 80072
እና 77266
ወደ 75254
=====================
'''


__author__ = 'eualuchiha@gmail.com'


from bs4 import BeautifulSoup
import requests

OUT_FILE = 'data/frequency_data.txt'
BASE_URL = 'https://corpora.fi.muni.cz/habit/run.cgi/wordlist?corpname=amwac16&refs=&wlmaxitems=1000&wlsort=f&subcnorm=freq&corpname=amwac16&reload=&wlattr=word&usengrams=0&ngrams_n=2&ngrams_max_n=2&nest_ngrams=0&wlpat=&wlminfreq=1&wlmaxfreq=0&wlfile=&wlblacklist=&wlnums=frq&wltype=simple&wlpage='
NUM_PAGES = 1000  # Crawl 1000 pages
TOTAL_WORDS_COUNT =0

def is_amharic(word):
    """Checks if a word contains Amharic characters."""
    for char in word:
        if ord(char) >= 0x1200 and ord(char) <= 0x137F:
            return True
    return False


if __name__ == '__main__':
    with open(OUT_FILE, 'w', encoding="utf-8") as f:
        for i in range(NUM_PAGES):
            print(f'Crawling page - {i + 1}')
            print("Total Number of Words: "+ str(TOTAL_WORDS_COUNT))
            url = f'{BASE_URL}{i + 1}'
            response = requests.get(url)
            soup = BeautifulSoup(response.content, 'html.parser')
            rows = soup.find('table').find_all('tr')[1:]

            if not rows:
                break

            for row in rows:
                word, frequency = row.find_all('td')
                if not is_amharic(word.text):
                    continue
                f.write(f'{word.text.strip()} {int(frequency.text)}\n')
                TOTAL_WORDS_COUNT+=int(frequency.text)
with open("total_words.txt", 'w') as of:
  of.write(f'TOTAL WORDS PROCESSED: {TOTAL_WORDS_COUNT}\n')
