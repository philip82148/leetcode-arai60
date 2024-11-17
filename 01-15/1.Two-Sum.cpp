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

    int right_i = nums.size() - 1;
    for (int left_i = 0; left_i < nums.size(); ++left_i) {
      auto left = nums[order[left_i]];
      while (right_i >= 0 && nums[order[right_i]] > target - left) --right_i;
      if (nums[order[right_i]] == target - left && left_i != right_i) {
        return {order[left_i], order[right_i]};
      }
    }

    return {};  // to avoid compile errors
  }
};