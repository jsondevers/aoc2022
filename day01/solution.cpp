#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> total_calories;
  string line;

  ifstream input("input.txt", ios::in);
  if (input.is_open()) {

    while (!input.eof()) {
      vector<int> elf_calories;
      while (getline(input, line)) {
        if (line.size() == 0) {
          int elf_sum = accumulate(elf_calories.begin(), elf_calories.end(), 0);
          total_calories.push_back(elf_sum);
          break;
        } else {
          int calorie = stoi(line);
          elf_calories.push_back(calorie);
        }
      }
    }
    input.close();
  }
  int top_three[3] = {0, 0, 0};
  for (int i = 0; i < 3; i++) {
    top_three[i] = *max_element(total_calories.begin(), total_calories.end());
    remove(total_calories.begin(), total_calories.end(), top_three[i]);
  }

  cout << top_three[0] << "\n";
  cout << top_three[1] << "\n";
  cout << top_three[2] << "\n";
  cout << top_three[0] + top_three[1] + top_three[2] << "\n";
}
