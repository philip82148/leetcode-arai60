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
    static const map<char, char> kClosingToOpening{
        {')', '('},
        {'}', '{'},
        {']', '['},
    };
    stack<char> opening_brackets;
    opening_brackets.push('*');  // sentinel
    for (auto bracket : brackets) {
      if (auto it = kClosingToOpening.find(bracket);
          it != kClosingToOpening.end()) {
        auto opening = it->second;
        if (opening_brackets.top() != opening) return false;
        opening_brackets.pop();
      } else {
        opening_brackets.push(bracket);
      }
    }
    return opening_brackets.size() == 1;
  }
};
