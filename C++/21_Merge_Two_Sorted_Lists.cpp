//
// Created by lmb on 2016/2/22.
// 1
//

// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

#include "all_header.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode (-1);
        ListNode *node = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                node->next = l1;
                l1 = l1->next;
            } else {
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }
        while (l1) {
            node->next = l1;
            l1 = l1->next, node = node->next;
        }
        while (l2) {
            node->next = l2;
            l2 = l2->next, node = node->next;
        }
        node = dummy->next;
        delete dummy;
        return node;
    }
};