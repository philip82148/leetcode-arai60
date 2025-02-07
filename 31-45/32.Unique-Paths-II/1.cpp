#if __has_include("../../debug.hpp")
#include "../../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <vector>

using namespace std;

// <時間>
// 13分
// <感想>
// 直前にUnique Pathsを解いていたので早く解けた。
// と思っていたらnum_paths[0][*]やnum_paths[*][0]の初期化処理が違うことに気づかず
// バグった。
// <コメント>
// - 他の人のPRを見ていてnum_paths[0][*]やnum_paths[*][0]の初期化処理を
//   途中でbreakさせることが出来ることに気づいた。
//   でも個人的にはこっちの方が(一貫性があってDPとしての)ロジックが分かりやすいかなぁと。
// - ロジックに問題があるわけではないので反復はレビューをもらってからしたい。
// <懸念点>
// - L49/L52とL56-L57のifに統一性が無いが、フォーマットするときの行幅の関係上、
//   統一すると行数が増えてしまうのでこうしている。
//   (L43をif(!obstacle...にすると{}でくくる必要があり、3行に増える)
//   が、あんまりよくないだろうか？(良くない気がするが聞いてみたい)
//   (行数は無駄に増やさない方が読みやすいと思っている)
// - 書いている時は気づかなかったが行列(二次元配列)にwidthやheightという単語は
//   あんまりしっくり来ておらず、避けていたことに気づいた。
//   気にしすぎでしょうか。(普段はnum_colsやnum_rows等)
//
//
//
//
//
//
//
//
//
// L39(行数調整用コメント)
class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid[0][0]) return 0;

    int height = obstacleGrid.size(), width = obstacleGrid[0].size();
    vector<vector<int>> num_paths(height, vector<int>(width));
    num_paths[0][0] = 1;
    for (int i = 1; i < height; ++i) {
      if (!obstacleGrid[i][0]) num_paths[i][0] = num_paths[i - 1][0];
    }
    for (int i = 1; i < width; ++i) {
      if (!obstacleGrid[0][i]) num_paths[0][i] = num_paths[0][i - 1];
    }
    for (int i = 1; i < height; ++i) {
      for (int j = 1; j < width; ++j) {
        if (obstacleGrid[i][j]) continue;
        num_paths[i][j] = num_paths[i - 1][j] + num_paths[i][j - 1];
      }
    }
    return num_paths[height - 1][width - 1];
  }
};
