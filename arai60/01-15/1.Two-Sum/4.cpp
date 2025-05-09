#if __has_include("../../../debug.hpp")
#include "../../../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> num_to_index;

    for (int i = 0; i < nums.size(); i++) {
      if (auto it = num_to_index.find(target - nums[i]);
          it != num_to_index.end()) {
        return {it->second, i};
      }
      num_to_index[nums[i]] = i;
    }

    return {};  // to avoid compile errors
  }
};
