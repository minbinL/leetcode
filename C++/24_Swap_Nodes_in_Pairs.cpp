//
// Created by lmb on 2016/2/22.
// 1
//

// Given a linked list, swap every two adjacent nodes and return its head.
// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.
// Your algorithm should use only constant space. You may not modify the values in the list,
// only nodes itself can be changed.

#include "all_header.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *dummy = new ListNode (0);
        dummy->next = head;
        ListNode *pre = dummy, *one = head, *two = head->next;
        while (two) {
            one->next = two->next;
            two->next = pre->next;
            pre->next = two;
            pre = one;
            one = one->next;
            if (one == NULL) {
                break;
            }
            two = one->next;
        }
        pre = dummy->next;
        delete dummy;
        return pre;
    }
};