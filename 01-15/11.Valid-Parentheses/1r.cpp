#if __has_include("../../debug.hpp")
#include "../../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <map>

using namespace std;

// <時間>
// 5分
// <感想>
class Solution {
 public:
  bool isValid(const string &brackets) {
    static const map<char, char> closing_to_opening{
        {')', '('},
        {'}', '{'},
        {']', '['},
    };
    stack<char> opening_brackets;
    for (auto bracket : brackets) {
      if (auto it = closing_to_opening.find(bracket);
          it != closing_to_opening.end()) {
        auto opening = it->second;
        if (!(!opening_brackets.empty() && opening_brackets.top() == opening)) {
          return false;
        }
        opening_brackets.pop();
      } else {
        opening_brackets.push(bracket);
      }
    }
    return opening_brackets.empty();
  }
};
