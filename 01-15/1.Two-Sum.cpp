#if __has_include("../debug.hpp")
#include "../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> order(nums.size());
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](auto a, auto b) {
      return nums[a] < nums[b];
    });

    int left_i = 0, right_i = nums.size() - 1;
    while (true) {
      auto left = nums[order[left_i]], right = nums[order[right_i]];
      auto sum = left + right;
      if (sum < target) {
        ++left_i;
      } else if (sum > target) {
        --right_i;
      } else {
        break;
      }
    }

    return {order[left_i], order[right_i]};
  }
};
