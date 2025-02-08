#if __has_include("../../debug.hpp")
#include "../../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <stack>
#include <vector>

using namespace std;

// <時間>
// 11分
// <疑問・不安点(・個人的な感想、違う意見があれば教えてほしいもの)>
// - 僕はTypeScriptをよく使っていて、クロージャーが好きである。
//   C++でも使いまくりたいと思っているので、使ってみた。
//   (が、避けた方がいいだろうか)
// - rowとcolが思いっきりshadowingしているけど、
//   別に良くないかと思ってあえて使っている(良くないか)
class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int num_rows = grid.size(), num_cols = grid[0].size();
    vector<vector<bool>> seen(num_rows, vector<bool>(num_cols));
    auto walkIsland = [&](int row, int col) {
      stack<pair<int, int>> positions;
      positions.emplace(row, col);
      while (!positions.empty()) {
        auto [row, col] = positions.top();
        positions.pop();
        if (seen[row][col]) continue;
        seen[row][col] = true;
        static constexpr pair<int, int> kDelta[4] = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto [d_row, d_col] : kDelta) {
          int next_row = row + d_row, next_col = col + d_col;
          if (!(0 <= next_row && next_row < num_rows && 0 <= next_col
                && next_col < num_cols)) {
            continue;
          }
          if (grid[next_row][next_col] == '0') continue;
          positions.emplace(next_row, next_col);
        }
      }
    };

    int num_islands = 0;
    for (int i = 0; i < num_rows; ++i) {
      for (int j = 0; j < num_cols; ++j) {
        if (grid[i][j] == '0' || seen[i][j]) continue;
        walkIsland(i, j);
        ++num_islands;
      }
    }
    return num_islands;
  }
};
