//
// Created by lmb on 2016/2/22.
// 1
//

// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

#include "all_header.h"


class Solution {
private:
    class cmp {
    public:
        bool operator () (ListNode *n1, ListNode *n2) {
            return n1->val < n2->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *dummy = new ListNode (0);
        int len = lists.size();
        if (len == 0) {
            return NULL;
        }
        multiset<*ListNode, cmp> heap;
        for (int i = 0; i < len; i++) {
            if (lists[i] != NULL) {
                heap.insert(lists[i]);
            }
        }
        ListNode *cur = dummy;
        while (!heap.empty()) {
            ListNode *node = *heap.begin();
            cur->next = node;
            cur = cur->next;
            heap.erase(heap.begin());
            if (node->next) {
                heap.insert(node->next);
            }
        }
        cur = dummy->next;
        delete dummy;
        return cur;
    }
};