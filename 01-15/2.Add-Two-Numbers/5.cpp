#if __has_include("../debug.hpp")
#include "../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    return AddTwoNumbersAux(l1, l2, false);
  }

 private:
  ListNode* AddTwoNumbersAux(ListNode* l1, ListNode* l2, bool carry) {
    auto sum = new ListNode();
    if (l1) sum->val += l1->val;
    if (l2) sum->val += l2->val;
    if (carry) ++sum->val;

    bool next_carry_over = false;
    if (sum->val >= 10) {
      next_carry_over = true;
      sum->val -= 10;
    }

    ListNode* next_l1 = l1 ? l1->next : nullptr;
    ListNode* next_l2 = l2 ? l2->next : nullptr;

    if (next_l1 || next_l2 || next_carry_over) {
      sum->next = AddTwoNumbersAux(next_l1, next_l2, next_carry_over);
    }

    return sum;
  }
};

class SolutionIterative {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy;
    auto node = &dummy;

    int carry = 0;
    while (l1 || l2 || carry) {
      int sum = carry;

      if (l1) {
        sum += l1->val;
        l1 = l1->next;
      }

      if (l2) {
        sum += l2->val;
        l2 = l2->next;
      }

      node = node->next = new ListNode(sum % 10);
      carry = sum / 10;
    }

    return dummy.next;
  }
};
