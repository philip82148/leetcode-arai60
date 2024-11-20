#if __has_include("../debug.hpp")
#include "../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    vector<int> ascii_to_last_index(256, -1);
    int max_len = 0, unique_string_begin = 0;

    for (int i = 0; i < s.size(); ++i) {
      if (ascii_to_last_index[s[i]] >= unique_string_begin) {
        unique_string_begin = ascii_to_last_index[s[i]] + 1;
      }

      // [unique_string_begin, i]が重複なしの範囲
      max_len = max(max_len, i - unique_string_begin + 1);
      ascii_to_last_index[s[i]] = i;
    }
    return max_len;
  }
};
