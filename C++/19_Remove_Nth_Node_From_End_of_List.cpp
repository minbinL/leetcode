//
// Created by lmb on 2016/2/22.
// 1
//

// Given a linked list, remove the nth node from the end of list and return its head.
// For example,
// Given linked list: 1->2->3->4->5, and n = 2.
//
// After removing the second node from the end, the linked list becomes 1->2->3->5.
// Note:
// Given n will always be valid.
// Try to do this in one pass.

#include "all_header.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || n <= 0) {
            return NULL;
        }
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *fast = dummy, *slow = dummy;
        int cnt = 0;
        while (cnt != n) {
            cnt += 1;
            fast = fast->next;
        }
        ListNode *pre = slow;
        while (fast != NULL) {
            pre = slow;
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *temp = pre->next;
        pre->next = pre->next->next;
        pre = dummy->next;
        delete temp, dummy;
        return pre;
    }
};