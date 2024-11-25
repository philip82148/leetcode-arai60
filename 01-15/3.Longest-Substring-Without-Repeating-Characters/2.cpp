#if __has_include("../../debug.hpp")
#include "../../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <algorithm>
#include <string>

using namespace std;

// <時間>
// 6分
// <疑問・不安点(・個人的な感想、違う意見があれば教えてほしいもの)>

// なお以下で出てくるコメントはプロダクト版にも書くつもりのコメント
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int ascii_to_last_index[128];
    for (int i = 0; i < 128; ++i) ascii_to_last_index[i] = -1;

    int max_len = 0, begin = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (ascii_to_last_index[s[i]] >= begin) {
        begin = ascii_to_last_index[s[i]] + 1;
      }
      ascii_to_last_index[s[i]] = i;

      // [begin, i]が文字が重複しない範囲
      max_len = max(max_len, i - begin + 1);
    }
    return max_len;
  }
};
