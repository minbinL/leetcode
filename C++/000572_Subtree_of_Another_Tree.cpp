//Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.
//
//Example 1:
//Given tree s:
//
//        3
//      / \
//     4   5
//    / \
//   1   2
//Given tree t:
//       4
//      / \
//     1   2
//Return true, because t has the same structure and node values with a subtree of s.
//Example 2:
//Given tree s:
//
//           3
//         / \
//        4   5
//       / \
//      1   2
//         /
//        0
//Given tree t:
//      4
//     / \
//    1   2
//Return false.


#include "all_header.h";

class Solution {
public:
    bool helper(TreeNode* s, TreeNode* t, bool start) {
        if (s == nullptr && t == nullptr) {
            return true;
        }
        if (s == nullptr || t == nullptr) {
            return false;
        }
        if (start && t->val != s->val) {
            return false;
        }
        if (s->left == nullptr && s->right == nullptr && t->left == nullptr &&
            t->right == nullptr && t->val != s->val) {
            if (t->val != s->val) {
                return false;
            }
            else {
                return true;
            }
        }

        bool status = false;
        if (s->val == t->val) {
            status = helper(s->left, t->left, true) && helper(s->right, t->right, true);
        }
        if (!status) {
            bool left = helper(s->left, t, false);
            bool right = helper(s->right, t, false);
            return left || right;
        }
        return status;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return helper(s, t, false);
    }
};