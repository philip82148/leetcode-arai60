#if __has_include("../../debug.hpp")
#include "../../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <bits/stdc++.h>

using namespace std;

// <時間>
// 7分
// <コメント>
// 1から着想を得て書いた
// <疑問・不安点(・個人的な感想、違う意見があれば教えてほしいもの)>
// - indexの他の命名候補はstart_index
// - is_checkedの他の命名候補はindex_is_checked
// - 競プロで書いてるBFSの自分の中のテンプレがあって、
//   ほぼそれにあてはめて書いているが、読みづらければ指摘してもらって
//   そのテンプレを修正したい(改行の頻度含め...)

// なお以下で出てくるコメントはプロダクト版にも書くつもりのコメント
class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    queue<int> indexes;
    vector<bool> is_checked(s.size());

    indexes.push(0);
    while (!indexes.empty()) {
      auto index = indexes.front();
      indexes.pop();

      if (index == s.size()) return true;

      if (is_checked[index]) continue;
      is_checked[index] = true;

      for (auto& word : wordDict) {
        if (s.compare(index, word.size(), word) == 0) {
          indexes.push(index + word.size());
        }
      }
    }
    return false;
  }
};
