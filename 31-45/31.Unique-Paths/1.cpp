#if __has_include("../debug.hpp")
#include "../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <vector>

using namespace std;

// <時間>
// 10分
// <感想>
// 最初計算量の見積もりをミスしていて再帰で書いていた。
// 途中で間違いに気づき、メモ化再帰→2次元DPみたいな思考の流れ。
// しばらく競プロ等をしていなかったのでDPを書くのに手こずった。
// なまるのが早いなと思う。(10分で書けたのが驚き)
// <コメント>
// - DPを競プロでしか書いたことがなく、
//   エンジニアにとってなじみのあるパターンが何か分からないので
//   他の人のレビューを見てみる
// - 見てみたが大して差があるように感じないのでこのまま完成とする
// - 一応いくつか気になる点があるが、
//   この例では質問するのに適切でないと感じるのでとりあえず次に進む
class Solution {
 public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> num_paths(m, vector<int>(n));
    for (int i = 0; i < m; ++i) num_paths[i][0] = 1;
    for (int i = 0; i < n; ++i) num_paths[0][i] = 1;
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        num_paths[i][j] = num_paths[i - 1][j] + num_paths[i][j - 1];
      }
    }
    return num_paths[m - 1][n - 1];
  }
};
