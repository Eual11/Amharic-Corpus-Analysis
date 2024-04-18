#include "../include/Tokenizer.h"
#include <stdexcept>
#include <string>
#include <winnls.h>

Tokenizer::Tokenizer(std::string filepath, size_t count,
                     Tokenizer::DATAFORMAT format) {
  Load_Data(filepath, count, format);
}
bool Tokenizer::load_mapped_data(std::string filepath, size_t count) {

  std::ifstream corpus(filepath);

  SetConsoleOutputCP(CP_UTF8);
  if (corpus.fail()) {
    std::cerr << "Couldn't Open File " << filepath
              << " Please supply a valid path for data\n";
    return false;
  }

  std::string readline;

  data_loaded = true;
  while (count && std::getline(corpus, readline, '\n')) {

    std::string word = readline.substr(0, readline.find_first_of(' ', 0));
    std::string word_freq = readline.substr(readline.find_first_of(' ', 0) + 1);

    try {

      long long freq = std::stoll(word_freq);
      word_map.push_back(std::make_pair(word, freq));

    } catch (const std::invalid_argument &e) {

      std::cerr << "Invalid Argument: " << e.what() << std::endl;
      // do something
      return false;
    } catch (const std::out_of_range &e) {
      // out of range
      //
      std::cerr << "Out of Range Error: " << e.what() << std::endl;
      return false;
    }
    count--;
  }
  std::sort(word_map.begin(), word_map.end(),
            [](const auto &a, const auto &b) { return a.second > b.second; });
  return true;
}
bool Tokenizer::Load_Data(std::string filepath, size_t count,
                          Tokenizer::DATAFORMAT format) {

  switch (format) {
  case DATAFORMAT::MAP: {
    // load a mapped data
    return load_mapped_data(filepath, count);
    break;

    break;
  }
  case DATAFORMAT::RAW: {
    // load a raw data
    // a raw data might be a data that still contains markups, invalid
    // characters and needs to be filtered and processed
    //
  }
  case DATAFORMAT::STRIPPED: {
    // load a stripped data
    // a stripped data is a data with markup and unnessary characters removed
    break;
  }
  }
  return false;
}
std::vector<long long> Tokenizer::getFrequencies() {
  std::vector<long long> freqs(word_map.size());

  auto it = word_map.begin();
  for (size_t i = 0; i < freqs.size(); i++) {
    //
    //
    freqs[i] = (*it).second;

    it++;
  }
  return freqs;
}

std::vector<std::string> Tokenizer::getWords() {
  std::vector<std::string> words(word_map.size());

  auto it = word_map.begin();

  for (size_t i = 0; i < words.size(); i++) {
    words[i] = (*it).first;

    it++;
  }

  return words;
}
