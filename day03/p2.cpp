#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream input("input.txt", ios::in);
  if (input.is_open()) {
    string line;
    int total_sum = 0;
    string first, second, third;
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

    while (!input.eof()) {
      while (getline(input, line)) {
        map<char, int> first_line = {
            {'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0}, {'f', 0},
            {'g', 0}, {'h', 0}, {'i', 0}, {'j', 0}, {'k', 0}, {'l', 0},
            {'m', 0}, {'n', 0}, {'o', 0}, {'p', 0}, {'q', 0}, {'r', 0},
            {'s', 0}, {'t', 0}, {'u', 0}, {'v', 0}, {'w', 0}, {'x', 0},
            {'y', 0}, {'z', 0}, {'A', 0}, {'B', 0}, {'C', 0}, {'D', 0},
            {'E', 0}, {'F', 0}, {'G', 0}, {'H', 0}, {'I', 0}, {'J', 0},
            {'K', 0}, {'L', 0}, {'M', 0}, {'N', 0}, {'O', 0}, {'P', 0},
            {'Q', 0}, {'R', 0}, {'S', 0}, {'T', 0}, {'U', 0}, {'V', 0},
            {'W', 0}, {'X', 0}, {'Y', 0}, {'Z', 0}};
        map<char, int> second_line = {
            {'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0}, {'f', 0},
            {'g', 0}, {'h', 0}, {'i', 0}, {'j', 0}, {'k', 0}, {'l', 0},
            {'m', 0}, {'n', 0}, {'o', 0}, {'p', 0}, {'q', 0}, {'r', 0},
            {'s', 0}, {'t', 0}, {'u', 0}, {'v', 0}, {'w', 0}, {'x', 0},
            {'y', 0}, {'z', 0}, {'A', 0}, {'B', 0}, {'C', 0}, {'D', 0},
            {'E', 0}, {'F', 0}, {'G', 0}, {'H', 0}, {'I', 0}, {'J', 0},
            {'K', 0}, {'L', 0}, {'M', 0}, {'N', 0}, {'O', 0}, {'P', 0},
            {'Q', 0}, {'R', 0}, {'S', 0}, {'T', 0}, {'U', 0}, {'V', 0},
            {'W', 0}, {'X', 0}, {'Y', 0}, {'Z', 0}};
        map<char, int> third_line = {
            {'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0}, {'f', 0},
            {'g', 0}, {'h', 0}, {'i', 0}, {'j', 0}, {'k', 0}, {'l', 0},
            {'m', 0}, {'n', 0}, {'o', 0}, {'p', 0}, {'q', 0}, {'r', 0},
            {'s', 0}, {'t', 0}, {'u', 0}, {'v', 0}, {'w', 0}, {'x', 0},
            {'y', 0}, {'z', 0}, {'A', 0}, {'B', 0}, {'C', 0}, {'D', 0},
            {'E', 0}, {'F', 0}, {'G', 0}, {'H', 0}, {'I', 0}, {'J', 0},
            {'K', 0}, {'L', 0}, {'M', 0}, {'N', 0}, {'O', 0}, {'P', 0},
            {'Q', 0}, {'R', 0}, {'S', 0}, {'T', 0}, {'U', 0}, {'V', 0},
            {'W', 0}, {'X', 0}, {'Y', 0}, {'Z', 0}};
        first = line;
        for (int j = 0; j < first.size(); j++) {
          if (first_line.find(first[j]) != first_line.end()) {
            first_line[first[j]]++;
          }
        }
        getline(input, line);
        second = line;
        for (int j = 0; j < second.size(); j++) {
          if (second_line.find(second[j]) != second_line.end()) {
            second_line[second[j]]++;
          }
        }

        getline(input, line);
        third = line;
        cout << third << "\n";
        for (int j = 0; j < third.size(); j++) {
          if (third_line.find(third[j]) != third_line.end()) {
            third_line[third[j]]++;
          }
        }

        for (auto const &[key, value] : first_line) {
          if ((second_line.find(key) != second_line.end()) &&
              (third_line.find(key) != third_line.end()) &&
              (first_line[key] > 0 && second_line[key] > 0 &&
               third_line[key] > 0)) {

            total_sum += priority[key];
          }
        }
      }
    }

    cout << "total sum:" << total_sum << "\n";
    input.close();
  } // end of if
}