#if __has_include("../debug.hpp")
#include "../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <bits/stdc++.h>

using namespace std;

// <時間>
// 18分
// <感想>
// 一周回って変なことしてしまったと思う
// 原因があるとすれば、O(2N)=O(N)を体で理解していないこと?
// それでも実行時間は早いかなと思ったら全然早くなかった
// 可能性があるとすればO(N)かかる方のif文の分岐かな
// 反省のために残しておく

// なお以下で出てくるコメントはプロダクト版にも書くつもりのコメント
class Solution {
 public:
  int firstUniqChar(string s) {
    vector<int> indexes(26, -1);
    vector<bool> is_repeated(26);
    for (int i = 0; i < s.size(); ++i) {
      auto alpha = s[i] - 'a';
      if (indexes[alpha] == -1) {
        indexes[alpha] = i;
      } else {
        is_repeated[alpha] = true;
      }
    }

    int min_index = s.size();
    for (int alpha = 0; alpha < 26; ++alpha) {
      if (indexes[alpha] != -1 && !is_repeated[alpha]) {
        min_index = min(min_index, indexes[alpha]);
      }
    }

    return min_index != s.size() ? min_index : -1;
  }
};
