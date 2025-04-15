#if __has_include("../../debug.hpp")
#include "../../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <vector>

using namespace std;

// <時間>
// 3分
// <感想>
class Solution {
 public:
  int findMin(vector<int>& nums) {
    if (nums.front() < nums.back()) return nums.front();
    int left = 0, right = nums.size() - 1;
    while (right - left > 1) {
      int mid = (left + right) / 2;
      if (nums[left] > nums[mid]) {
        right = mid;
      } else {
        left = mid;
      }
    }
    return nums[right];
  }
};
