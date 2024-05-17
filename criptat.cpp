#include <algorithm>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

ifstream fin("criptat.in");
ofstream fout("criptat.out");

struct Sorter {
  int freq;
  int total;
  double weight;

  bool operator < (const Sorter& other) const {
    // Descending order by weight
    return this->weight > other.weight;
  }
};

int main() {
  int n;
  fin >> n;
  vector<string> words(n);
  for (int i = 0; i < n; i++) {
    fin >> words[i];
  }

  vector<Sorter> value;
  int result = 0;

  // Iterate over each letter a-z
  for (int c = 0; c < 26; c++) {
    value.clear();
    for (const auto& s : words) {
      int freq = 0;
      for (char l : s) {
        if ((l - 'a') == c) {
          freq++;
        }
      }
      value.push_back({freq, static_cast<int>(s.size()),
                    static_cast<double>(freq) / s.size()});
    }

    // Sort by weight in descending order
    sort(value.begin(), value.end());

    int apps = value[0].freq;
    int len = value[0].total;

    for (int i = 1; i < static_cast<int>(value.size()); i++) {
      if ((apps + value[i].freq) > (len + value[i].total) / 2) {
        apps += value[i].freq;
        len += value[i].total;
      }
    }
    result = max(result, len);
  }

  fout << result << endl;  // Print the result to the output file
  return 0;
}
