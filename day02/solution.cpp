#include <bits/stdc++.h>
using namespace std;

int calc_round_score(map<char, int> points, char opponent, char self) {
  if (points[opponent] == points[self]) {
    return points[self] + 3;
  } else if (opponent == 'A') {
    if (self == 'Y') {
      return points['Y'] + 6;
    } else {
      return points['Z'];
    }
  } else if (opponent == 'B') {
    if (self == 'Z') {
      return points['Z'] + 6;
    } else {
      return points['X'];
    }
  } else {
    if (self == 'X') {
      return points['X'] + 6;
    } else {

      return points['Y'];
    }
  }
}

int play_move(map<char, int> points, char opponent, char self) {
  if (self == 'X') {
    if (opponent == 'A') {
      return calc_round_score(points, opponent, 'Z');
    } else if (opponent == 'B') {
      return calc_round_score(points, opponent, 'X');
    } else {
      return calc_round_score(points, opponent, 'Y');
    }
  } else if (self == 'Y') {
    if (opponent == 'A') {
      return calc_round_score(points, opponent, 'X');
    } else if (opponent == 'B') {
      return calc_round_score(points, opponent, 'Y');
    } else {
      return calc_round_score(points, opponent, 'Z');
    }

  } else {
    if (opponent == 'A') {
      return calc_round_score(points, opponent, 'Y');
    } else if (opponent == 'B') {
      return calc_round_score(points, opponent, 'Z');
    } else {
      return calc_round_score(points, opponent, 'X');
    }
  }
}

int main() {
  ifstream input("input.txt", ios::in);
  if (input.is_open()) {
    string line;
    int total_score = 0, moves_score = 0;
    map<char, int> points = {{'A', 1}, {'B', 2}, {'C', 3},
                             {'X', 1}, {'Y', 2}, {'Z', 3}};

    while (getline(input, line)) {
      char opponent = line[0];
      char self = line[2];
      if ((points.find(opponent) != points.end()) &&
          points.find(self) != points.end()) {
        total_score += calc_round_score(points, opponent, self);
        moves_score += play_move(points, opponent, self);
      }
    }
    input.close();
    cout << total_score << "\n";
    cout << moves_score << "\n";
  }
}