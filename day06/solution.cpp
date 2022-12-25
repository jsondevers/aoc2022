#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream input("input.txt", ios::in);
  if (input.is_open()) {

    while (!input.eof()) {
      set<char> buffer;
      string line;
      while (getline(input, line)) {
        for (int i = 0; i < line.size(); i++) {

          if (buffer.size() == 14) {
            // for (auto const &b : buffer) {
            //   cout << b << "\n";
            // }

            cout << i - 1 << "\n";
            break;
          } else if (buffer.find(line[i]) != buffer.end()) {
            buffer.clear();
          }
          buffer.insert({line[i]});
        }
      }
    }
  }
  input.close();
}
