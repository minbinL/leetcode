//You are given a binary tree in which each node contains an integer value.
//
//Find the number of paths that sum to a given value.
//
//The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
//
//The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.
//
//Example:
//
//        root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
//
//        10
//       /  \
//      5   -3
//     / \    \
//    3   2   11
//   / \   \
//  3  -2   1
//
//Return 3. The paths that sum to 8 are:
//
//1.  5 -> 3
//2.  5 -> 2 -> 1
//3. -3 -> 11


#include "all_header.h"


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int calculateSum(TreeNode* node, int sum, int tmpSum) {
        if (node == nullptr) {
            return 0;
        }
        int cnt = 0;
        tmpSum += node->val;
        if (tmpSum == sum) {
            cnt += 1;
        }
        cnt += calculateSum(node->left, sum, tmpSum);
        cnt += calculateSum(node->right, sum, tmpSum);
        return cnt;
    }
    int preorderTraversal(TreeNode* node, int sum) {
        if (node == nullptr) {
            return 0;
        }
        int cnt = calculateSum(node, sum, 0);
        cnt += preorderTraversal(node->left, sum);
        cnt += preorderTraversal(node->right, sum);
        return cnt;
    }
    int pathSum(TreeNode* root, int sum) {
        return preorderTraversal(root, sum);
    }
};

class Solution2 {
public:
    int helper(TreeNode* node, int sum, unordered_map<int, int> &map, int prev) {
        if (!node) {
            return 0;
        }
        int val = prev + node->val;
        int res = ((val == sum) ? 1 : 0) + (map.count(val - sum) ? map[val - sum] : 0);
        map[val]++;
        res = res + helper(node->left, sum, map, val) + helper(node->right, sum, map, val);
        map[val]--;
        return res;
    }
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> map;
        return helper(root, sum, map, 0);
    }
};