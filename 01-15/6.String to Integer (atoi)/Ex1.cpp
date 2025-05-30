#include <limits>
#if __has_include("../debug.hpp")
#include "../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <bits/stdc++.h>

using namespace std;

// こちらは番外編のlong long版です
// <時間>
// 16分
// <感想>
// <疑問・不安点(・個人的な感想、違う意見があれば教えてほしいもの)>
// - ret,digitとkMinの比較をpairを使って、
//   pair{ret, digit} <= pair{kMin / 10, kMin % 10}とやれば
//   いいことに気づいたが、可読性がいいと言えるのか分からなかったのでやらなかった
// - kMin / 10は2回出てきているが、
//   コンパイラの最適化で計算は1回になる認識(だがあっているか)

// なお以下で出てくるコメントはプロダクト版にも書くつもりのコメント
class SolutionLongLong {
 public:
  long long myAtol(string s) {
    int first_index = s.find_first_not_of(' ');
    if (first_index == string::npos) return 0;

    int sign = 1;
    if (s[first_index] == '-') {
      sign = -1;
      ++first_index;
    } else if (s[first_index] == '+') {
      ++first_index;
    }

    constexpr auto kMax = std::numeric_limits<long long>::max();
    constexpr auto kMin = std::numeric_limits<long long>::min();

    long long ret = 0;
    for (int i = first_index; i < s.size(); ++i) {
      if (!isdigit(s[i])) break;
      int digit = (s[i] - '0') * sign;
      if (sign == -1) {
        if (ret < kMin / 10 || (ret == kMin / 10 && digit <= kMin % 10)) {
          return kMin;
        }
      } else {
        if (ret > kMax / 10 || (ret == kMax / 10 && digit >= kMax % 10)) {
          return kMax;
        }
      }
      ret = ret * 10 + digit;
    }

    return ret;
  }
};
