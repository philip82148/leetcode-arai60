#if __has_include("../../debug.hpp")
#include "../../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <bits/stdc++.h>

using namespace std;

// <時間>
// 18分
// <コメント>
// <疑問・不安点(・個人的な感想、違う意見があれば教えてほしいもの)>
// 読みずれえなと思って2を作ったのでレビューしなくてもよいです

// なお以下で出てくるコメントはプロダクト版にも書くつもりのコメント
class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> checked(s.size());
    return WordBreakAux(s, 0, wordDict, checked);
  }

 private:
  bool WordBreakAux(
      string_view s, int start, vector<string>& wordDict, vector<bool>& checked
  ) {
    if (start == s.size()) return true;
    if (checked[start]) return false;
    for (auto& word : wordDict) {
      if (s.substr(start).starts_with(word)
          && WordBreakAux(s, start + word.size(), wordDict, checked)) {
        return true;
      }
    }
    checked[start] = true;
    return false;
  }
};
