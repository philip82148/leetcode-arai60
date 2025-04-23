#if __has_include("../../debug.hpp")
#include "../../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <map>
#include <stack>
#include <string>

using namespace std;

// <時間>
// 15分
// <コメント>
// - corresponding_bracketとopen_bracketは最初逆に名前を付けていた。
// - corresponding_bracketは最初corresponding_open_bracketとしていたが、
//   openはなくても伝わると思い消した。
// - だが、読む側に取ってどう見えるかは分からない。
// - correspondingみたいな意味の名前は付けることが多いと思うが、
//   もっと短めの単語はないものか。
class Solution {
 public:
  bool isValid(const string &brackets) {
    static const map<char, char> kCloseToOpen{
        {')', '('},
        {'}', '{'},
        {']', '['},
    };
    stack<char> open_brackets;
    open_brackets.push('\0');
    for (auto bracket : brackets) {
      // In the case `bracket` is an open bracket.
      auto close_and_open = kCloseToOpen.find(bracket);
      if (close_and_open == kCloseToOpen.end()) {
        open_brackets.push(bracket);
        continue;
      }

      // In the case `bracket` is a close bracket.
      auto open_bracket = close_and_open->second;
      auto corresponding_bracket = open_brackets.top();
      open_brackets.pop();
      if (corresponding_bracket != open_bracket) {
        return false;
      }
    }
    return open_brackets.size() == 1;
  }
};
