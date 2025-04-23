#if __has_include("../../debug.hpp")
#include "../../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <map>
#include <stack>
#include <string>

using namespace std;

// <時間>
// 10分
// <感想>
// 多分3.cppよりこっちの方が読みやすい。
// <コメント>
// - auto open_bracket = open_brackets.top();
//   で新しく変数を作ろうかとも思ったが、無駄に変数が多くても
//   読みづらいかなと思い作らないことにした。
class Solution {
 public:
  bool isValid(const string &brackets) {
    static const map<char, char> kOpenToClose{
        {'(', ')'},
        {'{', '}'},
        {'[', ']'},
    };
    stack<char> open_brackets;
    for (auto bracket : brackets) {
      // In the case `bracket` is an open bracket.
      if (kOpenToClose.contains(bracket)) {
        open_brackets.push(bracket);
        continue;
      }

      // In the case `bracket` is a close bracket.
      if (open_brackets.empty()) {
        return false;
      }
      auto close_bracket = kOpenToClose.at(open_brackets.top());
      open_brackets.pop();
      if (bracket != close_bracket) {
        return false;
      }
    }
    return open_brackets.empty();
  }
};
