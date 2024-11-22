#if __has_include("../debug.hpp")
#include "../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <bits/stdc++.h>

using namespace std;

// <時間>
// 1分
// <疑問・不安点(・個人的な感想、違う意見があれば教えてほしいもの)>
// - s[i] - 'a'が初見で伝わるのか問題
// - countsの他の命名候補としてalpha_countsがあった

// なお以下で出てくるコメントはプロダクト版にも書くつもりのコメント
class Solution {
 public:
  int firstUniqChar(string s) {
    vector<int> counts(26);
    for (int i = 0; i < s.size(); ++i) {
      ++counts[s[i] - 'a'];
    }
    for (int i = 0; i < s.size(); ++i) {
      if (counts[s[i] - 'a'] == 1) return i;
    }
    return -1;
  }
};
