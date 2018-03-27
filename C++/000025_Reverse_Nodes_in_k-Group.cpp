//
// Created by lmb on 2016/2/22.
// 1
//

// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
// If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
// You may not alter the values in the nodes, only nodes itself may be changed.
// Only constant memory is allowed.
// For example,
// Given this linked list: 1->2->3->4->5
// For k = 2, you should return: 2->1->4->3->5
// For k = 3, you should return: 3->2->1->4->5

#include "all_header.h"

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) {
            return head;
        }
        ListNode *dummy = new ListNode (0);
        dummy->next = head;
        ListNode *cur = dummy->next, *pre = dummy;
        int cnt = 1;
        while (cur) {
            if (cnt != k) {
                cur = cur->next;
                cnt++;
            } else {
                ListNode *next = cur->next;
                ListNode *node = pre->next, *record = pre->next;
                int count = 0;
                while (count != k) {
                    count++;
                    ListNode *temp = node->next;
                    node->next = pre->next;
                    pre->next = node;
                    node = temp;
                }
                pre = record;
                record->next = next;
                cur = next;
                cnt = 1;
            }
        }
        cur = dummy->next;
        delete dummy;
        return cur;
    }
};