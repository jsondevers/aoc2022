#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream input("example.txt", ios::in);
  if (input.is_open()) {
    string line;
    int priority_sum = 0;

    map<char, int> priority = {
        {'a', 1},  {'b', 2},  {'c', 3},  {'d', 4},  {'e', 5},  {'f', 6},
        {'g', 7},  {'h', 8},  {'i', 9},  {'j', 10}, {'k', 11}, {'l', 12},
        {'m', 13}, {'n', 14}, {'o', 15}, {'p', 16}, {'q', 17}, {'r', 18},
        {'s', 19}, {'t', 20}, {'u', 21}, {'v', 22}, {'w', 23}, {'x', 24},
        {'y', 25}, {'z', 26}, {'A', 27}, {'B', 28}, {'C', 29}, {'D', 30},
        {'E', 31}, {'F', 32}, {'G', 33}, {'H', 34}, {'I', 35}, {'J', 36},
        {'K', 37}, {'L', 38}, {'M', 39}, {'N', 40}, {'O', 41}, {'P', 42},
        {'Q', 43}, {'R', 44}, {'S', 45}, {'T', 46}, {'U', 47}, {'V', 48},
        {'W', 49}, {'X', 50}, {'Y', 51}, {'Z', 52}};

    while (getline(input, line)) {
      map<char, int> first_frequency = {
          {'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0}, {'f', 0}, {'g', 0},
          {'h', 0}, {'i', 0}, {'j', 0}, {'k', 0}, {'l', 0}, {'m', 0}, {'n', 0},
          {'o', 0}, {'p', 0}, {'q', 0}, {'r', 0}, {'s', 0}, {'t', 0}, {'u', 0},
          {'v', 0}, {'w', 0}, {'x', 0}, {'y', 0}, {'z', 0}, {'A', 0}, {'B', 0},
          {'C', 0}, {'D', 0}, {'E', 0}, {'F', 0}, {'G', 0}, {'H', 0}, {'I', 0},
          {'J', 0}, {'K', 0}, {'L', 0}, {'M', 0}, {'N', 0}, {'O', 0}, {'P', 0},
          {'Q', 0}, {'R', 0}, {'S', 0}, {'T', 0}, {'U', 0}, {'V', 0}, {'W', 0},
          {'X', 0}, {'Y', 0}, {'Z', 0}};
      map<char, int> second_frequency = {
          {'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0}, {'f', 0}, {'g', 0},
          {'h', 0}, {'i', 0}, {'j', 0}, {'k', 0}, {'l', 0}, {'m', 0}, {'n', 0},
          {'o', 0}, {'p', 0}, {'q', 0}, {'r', 0}, {'s', 0}, {'t', 0}, {'u', 0},
          {'v', 0}, {'w', 0}, {'x', 0}, {'y', 0}, {'z', 0}, {'A', 0}, {'B', 0},
          {'C', 0}, {'D', 0}, {'E', 0}, {'F', 0}, {'G', 0}, {'H', 0}, {'I', 0},
          {'J', 0}, {'K', 0}, {'L', 0}, {'M', 0}, {'N', 0}, {'O', 0}, {'P', 0},
          {'Q', 0}, {'R', 0}, {'S', 0}, {'T', 0}, {'U', 0}, {'V', 0}, {'W', 0},
          {'X', 0}, {'Y', 0}, {'Z', 0}};

      int mid = (line.size() - 1) / 2;
      string first_half = line.substr(0, mid + 1);
      string second_half = line.substr(mid + 1);
      for (int i = 0; i < first_half.size(); i++) {
        if (first_frequency.find(first_half[i]) != first_frequency.end()) {
          first_frequency[first_half[i]]++;
        }
      }

      for (int i = 0; i < second_half.size(); i++) {
        if (second_frequency.find(second_half[i]) != second_frequency.end()) {
          second_frequency[second_half[i]]++;
        }
      }

      for (auto const &[key, value] : first_frequency) {
        if ((second_frequency.find(key) != second_frequency.end()) &&
            (second_frequency[key] && first_frequency[key])) {
          priority_sum += priority[key];
        }
      }
    }
    input.close();
    cout << priority_sum << "\n";
  }
}