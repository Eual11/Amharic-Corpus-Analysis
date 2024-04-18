#include "../include/Tokenizer.h"
#include <matplot/matplot.h>
void Graph_Word_Freq(std::vector<std::string> &words,
                     std::vector<long long> &freq);
void Graph_Zipfs(const std::vector<long long> &freq);
int main() {
  Tokenizer token("../tool/data/frequency_data.txt", 100000,
                  Tokenizer::DATAFORMAT::MAP);

  std::vector<long long> freq = token.getFrequencies();

  std::vector<std::string> words = token.getWords();
  Graph_Word_Freq(words, freq);

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
  // gca()->ylim(-); // Set y-axis limits from -5 to 5

  auto rank = linspace(0, freq.size(), freq.size());
  auto c = linspace(1, 10, rank.size());

  std::vector<double> fr(freq.size());

  for (int i = 0; i < fr.size(); i++)
    fr[i] = std::log10(freq[i]);
  //  auto y = transform(freq, [&](long long x) { return static_cast<double>(x);
  //  });
  auto current_axis = gca();

  // the font must be an Ethiopic type font in order to render the graph and
  // text correctly
  current_axis->font("Nyala");
  current_axis->xlabel("Frequency Rank");
  current_axis->ylabel("Frequency(Logarithmic)");

  current_axis->title("Zipf's Law on Amharic Language");

  scatter(rank, fr, std::vector<double>{}, c);
  show();
}
