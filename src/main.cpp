#include "../include/Tokenizer.h"
#include "matplot/freestanding/plot.h"
#include "matplot/matplot.h"
void Graph_Word_Freq(std::vector<std::string> &words,
                     std::vector<long long> &freq);
void Graph_Zipfs(const std::vector<long long> &freq);
int main(int argc, char **argv) {

  int SAMPLE_SIZE = 1000;
  char path_to_data[] = "../tool/data/frequency_data.txt";

  std::string pathString(path_to_data);
  Tokenizer::DATAFORMAT format = Tokenizer::DATAFORMAT::MAP;
  if (argc == 1) {

    std::printf("USAGE: %s [sample_size] [path_to_data] [data_format]\n",
                argv[0]);

    std::printf("Program running with default parameters\n sample_size = "
                "%d\npath_to_data = %s\n data_format=%d\n ",
                SAMPLE_SIZE, path_to_data, static_cast<int>(format));
  } else if (argc >= 4) {
    SAMPLE_SIZE = std::stoi(argv[1]);
    pathString = argv[2];
  }
  Tokenizer token(path_to_data, SAMPLE_SIZE, Tokenizer::DATAFORMAT::MAP);

  std::vector<long long> freq = token.getFrequencies();

  std::vector<std::string> words = token.getWords();

  // histogram
  /* Graph_Word_Freq(words, freq); */

  // Zipf Distribution
  Graph_Zipfs(freq);
  return 0;
}

void Graph_Word_Freq(std::vector<std::string> &words,
                     std::vector<long long> &freq) {
  using namespace matplot;
  auto fig = figure();
  fig->size(1280, 720);
  // gca()->ylim(-); // Set y-axis limits from -5 to 5

  auto current_axis = gca();

  // the font must be an Ethiopic type font in order to render the graph and
  // text correctly
  current_axis->font("Nyala");
  current_axis->xlabel("Words");
  current_axis->ylabel("Frequency");

  current_axis->title("Frequency Distribution of Amharic Words");

  bar(current_axis, freq);
  gca()->x_axis().ticklabels(words);
  show();
}
void Graph_Zipfs(const std::vector<long long> &freq) {
  using namespace matplot;

  auto rank = linspace(0, freq.size(), freq.size());
  auto c = linspace(1, 10, rank.size());

  std::vector<double> logRank(freq.size());
  for (int i = 0; i < logRank.size(); i++) {
    logRank[i] = std::log10(i);
  }

  std::vector<double> fr(freq.size());

  for (int i = 0; i < fr.size(); i++)
    fr[i] = std::log10(freq[i]);
  auto current_axis = gca();

  // the font must be an Ethiopic type font in order to render the graph and
  // text correctly
  current_axis->font("Nyala");
  current_axis->xlabel("Frequency Rank");
  current_axis->ylabel("Frequency(Logarithmic)");

  current_axis->title("Zipf's Law on Amharic Language");

  scatter(logRank, fr, std::vector<double>{}, c);

  //

  show();
}
