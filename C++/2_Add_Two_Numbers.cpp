//
// Created by lmb on 2016/2/22.
// 1
//

//You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order
//and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8
#include "all_header.h"

// Time: O(n)
// Space: O(1)

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL ) {
            return  l2;
        } else if (l2 == NULL) {
            return l1;
        }
        int carry = 0;
        ListNode *dummy = new ListNode (0);
        ListNode *cur = dummy;
        while (l1 && l2) {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            cur->next = new ListNode(sum);
            cur = cur->next, l1 = l1->next, l2 = l2->next;
        }
        while (l1) {
            int sum = l1->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            cur->next = new ListNode(sum);
            cur = cur->next, l1 = l1->next;
        }
        while (l2) {
            int sum = l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            cur->next = new ListNode(sum);
            cur = cur->next, l2 = l2->next;
        }
        if (carry) {
            cur->next = new ListNode (carry);
        }
        cur = dummy->next;
        delete dummy;
        dummy = nullptr;
        return cur;
    }
};