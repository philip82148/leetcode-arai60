#if __has_include("../debug.hpp")
#include "../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> num_to_index;

    for (int i = 0; i < nums.size(); i++) {
      auto diff = target - nums[i];
      if (num_to_index.count(diff)) {
        return {num_to_index[diff], i};
      }
      num_to_index[nums[i]] = i;
    }

    return {};  // to avoid compile errors
  }
};
