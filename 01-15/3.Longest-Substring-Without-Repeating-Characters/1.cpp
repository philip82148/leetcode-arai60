#if __has_include("../debug.hpp")
#include "../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <bits/stdc++.h>

using namespace std;

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

      // [unique_str_begin, i]が重複なしの範囲
      max_len = max(max_len, i - unique_str_begin + 1);
      char_code_to_last_index[char_code] = i;
    }
    return max_len;
  }
};
