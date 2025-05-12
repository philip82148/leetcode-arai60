#if __has_include("../../debug.hpp")
#include "../../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <stack>
#include <vector>

using namespace std;

// <時間>
// 6分
// <疑問・不安点(・個人的な感想、違う意見があれば教えてほしいもの)>
// - dr, dcって伝わるかな
// - new_という命名が悪いとは言わないが、
//   この場合個人的にnew_row, new_colはダサさ(初心者感)を感じるのだが
//   気にし過ぎかな
class Solution {
 public:
  int numIslands(const vector<vector<char>>& grid) {
    int num_rows = grid.size(), num_cols = grid[0].size();
    vector<vector<bool>> seen(num_rows, vector<bool>(num_cols));
    auto WalkIslands = [&](int start_row, int start_col) {
      stack<pair<int, int>> positions;
      positions.emplace(start_row, start_col);
      while (!positions.empty()) {
        auto [row, col] = positions.top();
        positions.pop();
        if (seen[row][col]) continue;
        seen[row][col] = true;
        static constexpr pair<int, int> kDelta[4] = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto [dr, dc] : kDelta) {
          int new_row = row + dr, new_col = col + dc;
          if (0 <= new_row && new_row < num_rows && 0 <= new_col
              && new_col < num_cols && grid[new_row][new_col] == '1') {
            positions.emplace(new_row, new_col);
          }
        }
      }
    };

    int num_islands = 0;
    for (int i = 0; i < num_rows; ++i) {
      for (int j = 0; j < num_cols; ++j) {
        if (grid[i][j] == '0' || seen[i][j]) continue;
        WalkIslands(i, j);
        ++num_islands;
      }
    }
    return num_islands;
  }
};
