#include "../include/Tokenizer.h"
#include <matplot/matplot.h>

int main() {
  Tokenizer token("../tool/data/frequency_data.txt", 15,
                  Tokenizer::DATAFORMAT::MAP);

  std::vector<long long> freq = token.getFrequencies();

  std::vector<std::string> words = token.getWords();

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
  gca()->xlim({0, 10}); // Set x-axis limits from 0 to 10
  gca()->x_axis().ticklabels(words);
  show();
}
