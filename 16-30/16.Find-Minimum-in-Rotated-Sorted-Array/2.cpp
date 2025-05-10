#if __has_include("../../debug.hpp")
#include "../../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <vector>

using namespace std;

// <時間>
// 2分
// <感想>
// while(left<right)で書いてみて思ったが、意外に書きやすいと感じた。
// 今まではnums[left]がtrue、nums[right]がfalseとなるように考えていたけど、
// nums[left]がfalseになることを許可する(mid+1)することで、終了条件が
// 考えやすくなったと思う
class Solution {
 public:
  int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      int mid = (left + right) / 2;
      if (nums[mid] > nums[right]) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return nums[right];
  }
};
