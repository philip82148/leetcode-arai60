#if __has_include("../../debug.hpp")
#include "../../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <algorithm>

using namespace std;

// <時間>
// 1分
// <疑問・不安点(・個人的な感想、違う意見があれば教えてほしいもの)>
class Solution {
 public:
  int firstUniqChar(string s) {
    int alphabet_to_count[26];
    fill(alphabet_to_count, alphabet_to_count + 26, 0);
    for (auto c : s) {
      ++alphabet_to_count[c - 'a'];
    }
    for (int i = 0; i < s.size(); ++i) {
      if (alphabet_to_count[s[i] - 'a'] == 1) return i;
    }
    return -1;
  }
};
