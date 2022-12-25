#include <bits/stdc++.h>
using namespace std;

int main() {
  srand((unsigned)time(NULL));
  map<int, string> choices = {
      {1, "Python"}, {2, "Java"}, {3, "C++"}, {4, "Rust"}, {5, "C#"}, {6, "Go"},
  };
  int today = 1 + (rand() % 6);

  cout << choices[today] << "\n";
  return 1;
}