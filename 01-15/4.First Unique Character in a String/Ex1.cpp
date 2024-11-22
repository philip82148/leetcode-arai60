#include <algorithm>
#if __has_include("../debug.hpp")
#include "../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <bits/stdc++.h>

using namespace std;

// こちらは番外編です。入力がstreamだったときです。
// <時間>
// Ex2も併せて13分
// <疑問・不安点(・個人的な感想、違う意見があれば教えてほしいもの)>
// - 2バージョン作っている。
//   Ex2の方がメモリもコード量も少なくて好きなのだが、アクロバティックなので
//   可読性大丈夫かな…と思って無印の方も残している。
//   なお、intの代わりにsize_tを使えばフラグと値の範囲が実際被ることはない。
//   string::nposだってstatic_cast<size_t>(-1)である。

// なお以下で出てくるコメントはプロダクト版にも書くつもりのコメント
class SolutionStream {
 public:
  SolutionStream() : is_repeated(26), last_indexes(26, -1), index(0) {}

  int firstUniqChar(char c) {
    int alpha = c - 'a';
    if (last_indexes[alpha] == -1) {
      last_indexes[alpha] = index;
    } else {
      is_repeated[alpha] = true;
    }

    int min_index = INT_MAX;
    for (int alpha = 0; alpha < 26; ++alpha) {
      if (last_indexes[alpha] != -1 && !is_repeated[alpha]) {
        min_index = min(min_index, last_indexes[alpha]);
      }
    }

    return min_index != INT_MAX ? min_index : -1;
  }

 private:
  vector<int> is_repeated;
  vector<int> last_indexes;
  int index;
};

class SolutionStream2 {
 public:
  SolutionStream2() : first_index_or_repeated(26, kNotUsed), index(0) {}

  int firstUniqChar(char c) {
    int alpha = c - 'a';
    if (first_index_or_repeated[alpha] == kNotUsed) {
      first_index_or_repeated[alpha] = index;
    } else {
      first_index_or_repeated[alpha] = kRepeated;
    }
    ++index;

    auto first_index = *min_element(
        first_index_or_repeated.begin(), first_index_or_repeated.end()
    );

    return first_index < index ? first_index : -1;
  }

 private:
  static constexpr int kNotUsed = INT_MAX;
  static constexpr int kRepeated = INT_MAX - 1;
  vector<int> first_index_or_repeated;
  int index;
};
