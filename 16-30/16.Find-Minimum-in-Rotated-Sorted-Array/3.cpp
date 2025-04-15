#if __has_include("../../debug.hpp")
#include "../../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <vector>

using namespace std;

// <時間>
// 2分
// <感想>
// この問題2分探索としてはシンプルすぎる気がする
// (あるか分からないが)もっとif分の条件式とか区間の考え方?とかが
// 凝ったやつをやってみたい
class Solution {
 public:
  int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      int mid = (left + right) / 2;
      if (nums[mid] <= nums.back()) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return nums[right];
  }
};
