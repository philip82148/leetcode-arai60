#if __has_include("../debug.hpp")
#include "../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <bits/stdc++.h>

using namespace std;

// <時間>
// 8分
// <疑問・不安点(・個人的な感想、違う意見があれば教えてほしいもの)>
// 1.2の方に書く

// なお以下で出てくるコメントはプロダクト版にも書くつもりのコメント
class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1) return s;

    vector<string> rows(numRows);
    int direction = 1, row = 0;
    for (int i = 0; i < s.size(); ++i) {
      rows[row] += s[i];
      if (direction == 1) {
        if (row == numRows - 1) {
          direction = -1;
        }
      } else {
        if (row == 0) {
          direction = 1;
        }
      }
      row += direction;
    }
    return reduce(rows.begin(), rows.end());
  }
};
