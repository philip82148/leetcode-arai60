#if __has_include("../debug.hpp")
#include "../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <bits/stdc++.h>

using namespace std;

// <時間>
// 14分
// <感想>
// C++で解くと歯ごたえの無い問題になってしまった気がする
// と感じているので色々指摘してもらえると助かります
// <疑問・不安点(・個人的な感想、違う意見があれば教えてほしいもの)>
// - 他の回答者の回答を見てif文内でreturn INT_MAX出来ることに気づいた
//   でも、多分ret変数を用意しているのでそれをreturnするという意識があった
//   からやらなかったように思う。どっちでもよいとは思うが、ret変数を用意
//   した状態で早期returnするのをどう思うか

// なお以下で出てくるコメントはプロダクト版にも書くつもりのコメント
class Solution {
 public:
  int myAtoi(string s) {
    int first_index = s.find_first_not_of(' ');
    if (first_index == string::npos) return 0;

    int sign = 1;
    if (s[first_index] == '-') {
      sign = -1;
      ++first_index;
    } else if (s[first_index] == '+') {
      ++first_index;
    }

    long long ret = 0;
    for (int i = first_index; i < s.size(); ++i) {
      if (!isdigit(s[i])) break;
      ret *= 10;
      ret += (s[i] - '0') * sign;
      if (ret > INT_MAX) {
        ret = INT_MAX;
        break;
      } else if (ret < INT_MIN) {
        ret = INT_MIN;
        break;
      }
    }

    return ret;
  }
};
