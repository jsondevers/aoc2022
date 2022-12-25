#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool row_border(vector<vector<int>> &grid, int row) {
  return row == 0 || row == grid.size() - 1 ? true : false;
}
bool col_border(vector<vector<int>> &grid, int col) {
  return col == 0 || col == grid[0].size() - 1 ? true : false;
}
bool is_border(vector<vector<int>> &grid, int row, int col) {
  return row_border(grid, row) || col_border(grid, col);
}

vector<int> north(vector<vector<int>> &grid, int row, int col) {
  vector<int> up;
  int trees = 0;
  for (int r = row - 1; r >= 0; r--) {
    if (grid[r][col] >= grid[row][col]) {
      up.push_back(0);
      up.push_back(trees + 1);
      return up;
    }
    trees++;
  }
  up.push_back(1);
  up.push_back(trees);
  return up;
}
vector<int> south(vector<vector<int>> &grid, int row, int col) {
  vector<int> down;
  int trees = 0;
  for (int r = row + 1; r < grid.size(); r++) {
    if (grid[r][col] >= grid[row][col]) {
      down.push_back(0);
      down.push_back(trees + 1);
      return down;
    }
    trees++;
  }
  down.push_back(1);
  down.push_back(trees);
  return down;
}
vector<int> west(vector<vector<int>> &grid, int row, int col) {
  vector<int> left;
  int trees = 0;
  for (int c = col - 1; c >= 0; c--) {
    if (grid[row][c] >= grid[row][col]) {
      left.push_back(0);
      left.push_back(trees + 1);
    }
    trees++;
  }
  left.push_back(1);
  left.push_back(trees);
  return left;
}

vector<int> east(vector<vector<int>> &grid, int row, int col) {
  vector<int> right;
  int trees = 0;
  for (int c = col + 1; c < grid[0].size(); c++) {
    if (grid[row][c] >= grid[row][col]) {
      right.push_back(0);
      right.push_back(trees + 1);
      return right;
    }
    trees++;
  }
  right.push_back(1);
  right.push_back(trees);
  return right;
}

int calculate_scenic_score(vector<vector<int>> &grid, int row, int col) {

  vector<int> left = west(grid, row, col);
  vector<int> right = east(grid, row, col);
  vector<int> up = north(grid, row, col);
  vector<int> down = south(grid, row, col);

  int left_value = left[1] ? left[1] : 1;
  int right_value = right[1] ? right[1] : 1;
  int up_value = up[1] ? up[1] : 1;
  int down_value = down[1] ? down[1] : 1;

  return (up_value * down_value * left_value * right_value);
}

bool is_visible(vector<vector<int>> &grid, int row, int col) {
  vector<int> left = west(grid, row, col);
  vector<int> right = east(grid, row, col);
  vector<int> up = north(grid, row, col);
  vector<int> down = south(grid, row, col);

  return (left[0] || right[0] || up[0] || down[0]);
}

int main() {
  int visible_trees = 0;
  int scenic_score = -1;
  vector<vector<int>> grid;
  ifstream input("input.txt", ios::in);

  if (input.is_open()) {
    string line;
    while (getline(input, line)) {
      vector<int> row;
      for (int col = 0; col < line.size(); col++) {
        row.push_back(line[col] - '0');
      }
      grid.push_back(row);
    }
  }

  for (int row = 1; row < grid.size() - 1; row++) {
    for (int col = 1; col < grid[0].size() - 1; col++) {
      if (is_visible(grid, row, col)) {
        cout << "(" << row << "," << col << ")"
             << " ";
        visible_trees++;
        int current_tree = calculate_scenic_score(grid, row, col);

        scenic_score = max(current_tree, scenic_score);
      }
    }
    cout << "\n";
  }
  int border_trees = (2 * (grid.size() - 1)) + (2 * (grid[0].size() - 1));
  cout << "visible trees: " << visible_trees << "\n";
  cout << "border trees: " << border_trees << "\n";
  cout << "total trees: " << visible_trees + border_trees << "\n";
  cout << "scenic score: " << scenic_score << "\n";
}