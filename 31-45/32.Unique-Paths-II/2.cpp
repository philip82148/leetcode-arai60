#if __has_include("../../debug.hpp")
#include "../../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <vector>

using namespace std;

// <時間>
// 4分
// <感想>
class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid[0][0]) return 0;

    int num_rows = obstacleGrid.size(), num_cols = obstacleGrid[0].size();
    vector<vector<int>> num_paths(num_rows, vector<int>(num_cols));
    num_paths[0][0] = 1;
    for (int i = 0; i < num_rows; ++i) {
      if (obstacleGrid[i][0]) break;
      num_paths[i][0] = 1;
    }
    for (int i = 0; i < num_cols; ++i) {
      if (obstacleGrid[0][i]) break;
      num_paths[0][i] = 1;
    }
    for (int i = 1; i < num_rows; ++i) {
      for (int j = 1; j < num_cols; ++j) {
        if (obstacleGrid[i][j]) continue;
        num_paths[i][j] = num_paths[i - 1][j] + num_paths[i][j - 1];
      }
    }
    return num_paths[num_rows - 1][num_cols - 1];
  }
};
