//Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
//The same repeated number may be chosen from C unlimited number of times.
//Note:
//All numbers (including target) will be positive integers.
//The solution set must not contain duplicate combinations.
//For example, given candidate set [2, 3, 6, 7] and target 7,
//A solution set is:
//[
//[7],
//[2, 2, 3]
//]

#include "all_header.h"

class Solution {
public:
    void helper(vector<vector<int>> &result, vector<int> &cur_status, vector<int>& candidates, int cur_sum, int target, int pos, int end) {
        if (pos >= end || cur_sum > target)
        {
            return;
        }

        if (cur_sum == target)
        {
            vector<int> tmp = cur_status;
            result.push_back(tmp);
            return;
        }

        cur_status.push_back(candidates[pos]);
        helper(result, cur_status, candidates, cur_sum + candidates[pos], target, pos, end);
        cur_status.pop_back();
        helper(result, cur_status, candidates, cur_sum, target, pos+1, end);
    }

    static bool cmp(int x, int y)
    {
        return x > y;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        int end = candidates.size();
        if (candidates.size() <= 0)
        {
            return result;
        }
        sort(candidates.begin(), candidates.end(), cmp);
        vector<int> cur_status;

        helper(result, cur_status, candidates, 0, target, 0, end);
        return result;
    }

    static void test()
    {
        Solution *s = new Solution();
        vector<int> candidates = {48,22,49,24,26,47,33,40,37,39,31,46,36,43,45,34,28,20,29,25,41,32,23};
        int target = 69;
        vector<vector<int>> result = s->combinationSum(candidates, target);
        for (auto iter_vec = result.begin(); iter_vec != result.end(); ++iter_vec)
        {
            for (auto iter_int = iter_vec->begin(); iter_int != iter_vec->end(); ++iter_int)
            {
                cout << *iter_int << "\t";
            }
            cout << endl;
        }
    }
};