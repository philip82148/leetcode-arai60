#if __has_include("../debug.hpp")
#include "../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <bits/stdc++.h>

using namespace std;

// <時間>
// 8分
// <疑問・不安点(・個人的な感想、違う意見があれば教えてほしいもの)>
// - 他の人のを見ていて1.1の25行目のif文が要らないことに気づいたので
//   それを消したもの。
// - 言われた通り、ジグザグに並べた。先頭から順に追加すべきインデックスを
//   計算することも考えたが素直に書いた方が可読性は良いだろうと考えこうした。
// - 前にそうやってこの問題を解いたことがあり、SolutionOldのところに
//   その回答を載せた。一応この方が速度は速い。
// - row == numRows - 1かrow >= numRows - 1か
// - 細かい話だが28行目を空けるか否か
//   (自分はフェーズを分ける意味で改行を使いがち)

// なお以下で出てくるコメントはプロダクト版にも書くつもりのコメント
class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1) return s;

    vector<string> rows(numRows);
    int direction = 1, row = 0;
    for (int i = 0; i < s.size(); ++i) {
      rows[row] += s[i];
      if (row == numRows - 1) {
        direction = -1;
      } else if (row == 0) {
        direction = 1;
      }
      row += direction;
    }
    return reduce(rows.begin(), rows.end());
  }
};

class SolutionOld {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1) return s;
    string retval;
    for (int row = 0; row < numRows; ++row) {
      for (int i = row; i - row * 2 < static_cast<int>(s.size());
           i += numRows * 2 - 2) {
        if (row > 0 && row < numRows - 1) {
          if (i - row * 2 > 0) retval += s[i - row * 2];
        }
        if (i < s.size()) retval += s[i];
      }
    }
    return retval;
  }
};
