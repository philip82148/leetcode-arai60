#if __has_include("../../debug.hpp")
#include "../../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <stack>
#include <vector>

using namespace std;

// <時間>
// 11分
// <感想>
// 競プロで書きまくっているBFS/DFSであるが、エンジニアにとって
// 読みやすいパターンは何か調べなければならない。
// なお、久しぶりで書くのに時間がかかってしまったが、
// その他のパターンもいくつか見えている状態なので反復は一旦スキップ
// <他の人のレビューを読んでコメント>
// - row, colの命名について。こういうのが欲しかった。
// https://github.com/olsen-blue/Arai60/pull/17/files#r1931573071
// - 4方向のpushをどう処理するか
// https://github.com/katataku/leetcode/pull/16/files#r1905332545
// - 範囲内の判定をどうするか
// https://github.com/Hurukawa2121/leetcode/pull/17/files#r1898908077
// - 意外とC++でクロージャ使うのありなんだな
// https://github.com/Hurukawa2121/leetcode/pull/17/files#r1898590021
// - 競プロで見慣れ過ぎているパターンなので違和感がなかったが、
//   BFS部分は別関数にしないと読みづらいだろうか?
// - walkいいな
// - pairやtupleを使わなくてもいいケース
// https://github.com/colorbox/leetcode/pull/31/files#r1881109902
// - chromium code searchではvisitedとseenの両方を確認
// - コーディングに対する根本的な何かをつかんだ気がする
// - pairの場合emplaceもpushも同じ結果になると思っているのだけど、
//   違うかな。まあemplaceの方が無難か
class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int num_rows = grid.size(), num_cols = grid[0].size();
    vector<vector<bool>> visited(num_rows, vector<bool>(num_cols));
    int num_islands = 0;
    for (int i = 0; i < num_rows; ++i) {
      for (int j = 0; j < num_cols; ++j) {
        if (grid[i][j] == '0' || visited[i][j]) continue;
        ++num_islands;

        stack<pair<int, int>> positions;
        positions.push({i, j});
        while (!positions.empty()) {
          auto [row, col] = positions.top();
          positions.pop();
          if (visited[row][col]) continue;
          if (grid[row][col] == '0') continue;
          visited[row][col] = true;
          if (row + 1 < num_rows) positions.push({row + 1, col});
          if (row - 1 >= 0) positions.push({row - 1, col});
          if (col + 1 < num_cols) positions.push({row, col + 1});
          if (col - 1 >= 0) positions.push({row, col - 1});
        }
      }
    }
    return num_islands;
  }
};
