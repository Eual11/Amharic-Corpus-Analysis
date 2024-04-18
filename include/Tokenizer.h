#ifndef _TOKENIZER_H
#define _TOKENIZER_H
#include <Windows.h>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
class Tokenizer {

public:
  /**
   * @brief Enum representing different data formats.
   */
  enum class DATAFORMAT {
    /**
     * @brief Raw data format.
     *
     * Raw data might contain markups, invalid characters, and needs to be
     * filtered and processed.
     */
    RAW,

    /**
     * @brief Mapped data format.
     *
     * Mapped data is a word frequency format, where each word is associated
     * with its frequency.
     */
    MAP,

    /**
     * @brief Stripped data format.
     *
     * Stripped data is a data with markups and unnecessary characters removed.
     */
    STRIPPED
  };

public:
  Tokenizer() = default;
  Tokenizer(std::string filepath, size_t count, DATAFORMAT format);

  /**
   * @brief Loads data from a file .
   *
   * @param filepath The path to the data file.
   * @param count The number of data points to load.
   * @param format The format of the data file.
   * @return True if the data was loaded successfully, false otherwise.
   */
  bool Load_Data(std::string filepath, size_t count, DATAFORMAT format);
  /**
   * @brief Returns the frequencies of the loaded data.
   *
   * @return A vector containing the frequencies of the data points.
   */
  std::vector<long long> getFrequencies(void);

  /**
   * @brief Returns the words of the loaded data.
   *
   * @return A vector containing the words of the data points.
   */
  std::vector<std::string> getWords(void);

  // for debugging purpose
  /* void print_map() { */
  /*   for (const auto &[word, freq] : word_map) { */
  /*     std::cout << "word-> " << word << "   " */
  /*               << "freq-> " << freq << std::endl; */
  /*   } */
  /* } */

private:
  std::vector<std::pair<std::string, long long>> word_map;
  bool load_mapped_data(std::string filepath, size_t count);
  bool data_loaded = false;
};

#endif
