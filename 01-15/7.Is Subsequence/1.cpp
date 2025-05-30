#if __has_include("../debug.hpp")
#include "../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <bits/stdc++.h>

using namespace std;

// <時間>
// 1分
// <感想>
// <疑問・不安点(・個人的な感想、違う意見があれば教えてほしいもの)>
// - 20行目の後に改行を入れるかどうか
// - indexの命名をこだわるか迷った。
//   他の候補としてはsiとか(sのイテレータみたいな)。
//   リーダブルコードあったが、これは複数イテレータがあったときに
//   区別しやすいという話なので今回はしなかった

// なお以下で出てくるコメントはプロダクト版にも書くつもりのコメント
class Solution {
 public:
  bool isSubsequence(string s, string t) {
    if (s.size() == 0) return true;
    int index = 0;
    for (auto c : t) {
      if (s[index] == c) {
        ++index;
        if (index == s.size()) return true;
      }
    }
    return false;
  }
};
