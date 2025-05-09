#if __has_include("../../../debug.hpp")
#include "../../../debug.hpp"
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
    return _addTwoNumbers(l1, l2, false);
  }

 private:
  ListNode* _addTwoNumbers(ListNode* l1, ListNode* l2, bool carry_over) {
    auto sum = new ListNode();
    if (l1 != nullptr) sum->val += l1->val;
    if (l2 != nullptr) sum->val += l2->val;
    if (carry_over) ++sum->val;

    bool next_carry_over = false;
    if (sum->val >= 10) {
      next_carry_over = true;
      sum->val -= 10;
    }

    ListNode* next_l1 = l1 ? l1->next : nullptr;
    ListNode* next_l2 = l2 ? l2->next : nullptr;

    if (next_l1 || next_l2 || next_carry_over) {
      sum->next = _addTwoNumbers(next_l1, next_l2, next_carry_over);
    }

    return sum;
  }

 public:
  ListNode* addTwoNumbersIterative(ListNode* l1, ListNode* l2) {
    auto head = new ListNode(l1->val + l2->val);

    bool carry_over = head->val >= 10;
    if (carry_over) head->val -= 10;

    l1 = l1->next;
    l2 = l2->next;

    auto previous = head;
    while (l1 || l2 || carry_over) {
      auto current = new ListNode();
      if (l1) current->val += l1->val;
      if (l2) current->val += l2->val;
      if (carry_over) ++current->val;

      carry_over = current->val >= 10;
      if (carry_over) current->val -= 10;

      if (l1) l1 = l1->next;
      if (l2) l2 = l2->next;

      previous->next = current;
      previous = current;
    }

    return head;
  }
};
