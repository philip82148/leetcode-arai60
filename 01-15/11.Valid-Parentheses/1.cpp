#if __has_include("../../debug.hpp")
#include "../../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <map>

using namespace std;

// <時間>
// 10分
// <感想>
// これ正直10分じゃ無理だろ、と思っていたが意外と書けて嬉しい。
// 最初の方でどうするのがいいか少し時間を取って考えた。
// 最初に思い付いたのがpre変数を用意して、
// ひとつ前の文字に対応する括弧のみ受けつけ続けるみたいな(結局うまく行かなそう)。
// そっから何かの拍子にstackを使うことを思いつき、
// 途中でclosing_to_openingが必要になり
// switchで書いていたロジックをclosing_to_openingを使った
// ifに書き換えるという流れ
// <疑問・不安点(・個人的な感想、違う意見があれば教えてほしいもの)>
// - L49を空けるか否か
// - closing_to_openingとopening_bracketsのどちらを先に宣言するか
//   (細かいけど...)
// <他の人のを見てコメント>
// - なるほど。そういえばValid ParenthesesもCSZAPで触れていたかもしれない。
// https://discord.com/channels/1084280443945353267/1201211204547383386/1202541275115425822
// - そうか、closing_to_openingじゃなくてもopening_to_closingでもよかったのか…
//   うーん、でもその場合2回map::findすることになるな
// - stackに番兵を入れてstack::emptyを呼び出さなくていいようにしている
//   ものがあった。頭いい。
// - closing_to_opening定数だからスネークケースじゃなかったわ。
//
//
//
//
//
//
//
// L40(行数調整用コメント)
class Solution {
 public:
  bool isValid(string s) {
    static const map<char, char> closing_to_opening{
        {')', '('},
        {'}', '{'},
        {']', '['},
    };

    stack<char> opening_brackets;
    for (auto c : s) {
      if (auto it = closing_to_opening.find(c);
          it != closing_to_opening.end()) {
        auto opening = it->second;
        if (!opening_brackets.empty() && opening_brackets.top() == opening) {
          opening_brackets.pop();
        } else {
          return false;
        }
      } else {
        opening_brackets.push(c);
      }
    }
    return opening_brackets.empty();
  }
};
