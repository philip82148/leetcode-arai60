#if __has_include("../debug.hpp")
#include "../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <bits/stdc++.h>

using namespace std;

// <時間>
// 不明(次から測る)
// <選定事項と理由>
// mapではなくvector:最悪ケース(256文字すべて使う)のメモリはどちらも同じだから。
// <疑問・不安点(・個人的な感想、違う意見があれば教えてほしいもの)>
// - unique_str_beginの代わりにbegin。流石にbeginじゃ分からない？
//   他の人ので単にleftとしているものがあったが、これでもよいだろうか？
//   Goで書かれるとなぜか短くても理解できてしまうところがある。
// - iの代わりにend。これだとなんのendか分からない。ならunique_str_endは?
//   これもunique_str_end単体で使う場面があって気持ち悪い。
// - begin&end、またはfirst&lastは半開区間[begin,end)を表すイメージがある。
//   閉区間を表す単語はないものか。left&rightにそのイメージはありますか？
// - char_codeをasciiにしたら文字数が減ること。
//   でもasciiとは限らないと思った(なおその場合char_code_to...は0x80要素用意すれば十分か)

// なお以下で出てくるコメントはプロダクト版にも書くつもりのコメント
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    vector<int> char_code_to_last_index(256, -1);
    int max_len = 0, unique_str_begin = 0;

    for (int i = 0; i < s.size(); ++i) {
      unsigned char char_code = s[i];

      if (char_code_to_last_index[char_code] >= unique_str_begin) {
        unique_str_begin = char_code_to_last_index[char_code] + 1;
      }

      // [unique_str_begin, i]は文字が重複しない範囲
      max_len = max(max_len, i - unique_str_begin + 1);
      char_code_to_last_index[char_code] = i;
    }
    return max_len;
  }
};
