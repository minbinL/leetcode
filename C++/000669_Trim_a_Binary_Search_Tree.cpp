//Given a binary search tree and the lowest and highest boundaries as L and R, trim the tree so that all its elements lies in [L, R] (R >= L). You might need to change the root of the tree, so the result should return the new root of the trimmed binary search tree.
//
//    Example 1:
//    Input:
//        1
//      /  \
//     0    2
//
//     L = 1
//     R = 2
//
//    Output:
//      1
//       \
//        2
//    Example 2:
//    Input:
//       3
//     /   \
//    0    4
//    \
//    2
//   /
//  1
//
//    L = 1
//    R = 3
//
//      Output:
//      3
//     /
//    2
//   /
//  1



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include "all_header.h"


class Solution {
public:
    bool connect(TreeNode* node1, TreeNode* node2) {
        if (node1 == nullptr || node2 == nullptr) {
            return true;
        }
        if (node1->left == nullptr) {
            node1->left = node2;
            return true;
        }
        if (node1->right == nullptr) {
            node1->right = node2;
            return true;
        }
        return connect(node1->left, node2);
    }

    TreeNode* trimHelper(TreeNode* node, int L, int R) {
        if (node == nullptr) {
            return nullptr;
        }
        node->left = trimHelper(node->left, L, R);
        node->right = trimHelper(node->right, L, R);
        if (node->val >= L && node->val <= R) {
            return node;
        } else {
            if (node->left == nullptr) {
                return node->right;
            }
            if (node->right == nullptr) {
                return node->left;
            }
            connect(node->left, node->right);
            return node->left;
        }
    }

    TreeNode* trimBST(TreeNode* root, int L, int R) {
        TreeNode* dummy = new TreeNode(R);
        dummy->left = root;
        dummy = trimHelper(dummy, L, R);
        TreeNode* node = dummy->left;
        delete dummy;
        return node;
    }
};