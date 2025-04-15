#if __has_include("../../debug.hpp")
#include "../../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <vector>

using namespace std;

// <時間>
// 6分
// <感想>
// 直前に他の2分探索の問題を解いていたのですぐ解けるかと思っていたら
// (最初の早期リターンで)バグってしまった。まだまだ書き慣れていないみたい
// 書いてみて思ったが条件式はnums[mid]>=targetの方が分かりやすいかもしれない
// <他の人のコードを読んでコメント>
// - なるほど…、right=nums.size()とすること(半開区間)で最初の早期リターンを
// しなくてよくなるのか。色んなパターンがあるなあ。
class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    if (nums.back() < target) return nums.size();
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      int mid = (left + right) / 2;
      if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return left;
  }
};
