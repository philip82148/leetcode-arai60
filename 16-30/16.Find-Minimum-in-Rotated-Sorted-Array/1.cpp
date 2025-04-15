#if __has_include("../../debug.hpp")
#include "../../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <vector>

using namespace std;

// <時間>
// 11分
// <感想>
// いつもpartition_pointを使っているので生で書くのは初めてだ。
// 問題文の意味を理解するのに時間がかかったが、
// 結局nums[i]<nums[i+1]<...<nums[j]>nums[j+1]<nums[j+2]<...となる
// jを探せばいいと気づいた
// 二分探索とはあまり考えずにその考えをコード化するように意識してみたものの…
// その意味ではnums[left]<nums[mid]よりnums[left]>nums[mid]の方が分かりやすかったかも
// また感想を書きながら気づいたが、このコードならmidに関して+1する必要はなかったようだ
// <他の人のコードを読んでコメント>
// - なんか僕と同じようにleft<right-1で考えている人がいない…
//   nums[left]がnums[left-1]<nums[left]の端、nums[right]がその否定の端になるようにすると
//   いう風に考えたが…
//   でもその意味ではnums[-2]<nums[-1]の場合を最初にはじいた方が良かったな
// - なるほど。nums[-1]との比較でやってるのか。頭いいな
// - std::partition_pointの実装も読んでみる
//   あれ、std::partition_pointもleft<rightの条件式でwhileを回していた
//   leftはleft=mid+1で更新して、leftを返している
//   こっちの方が読みやすいのか?(可読性を最優先して書かれているとは限らないけど)
//   意思決定の理由が知りたい
class Solution {
 public:
  int findMin(vector<int>& nums) {
    int left = 0, right = nums.size();
    while (left < right - 1) {
      int mid = (left + right + 1) / 2;
      if (nums[left] < nums[mid]) {
        left = mid;
      } else {
        right = mid;
      }
    }
    return nums[right % nums.size()];
  }
};
