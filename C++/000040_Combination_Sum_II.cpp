//Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
//Each number in C may only be used once in the combination.
//Note:
//All numbers (including target) will be positive integers.
//The solution set must not contain duplicate combinations.
//For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
//A solution set is:
//[
//[1, 7],
//[1, 2, 5],
//[2, 6],
//[1, 1, 6]
//]

#include "all_header.h"

class Solution {
public:
    void helper(vector<int>& candidates, int target, vector<int>& cur_state, int pos, int end, int sum, vector<vector<int>>& result) {
        if (sum == target)
        {
            result.push_back(cur_state);
            return;
        }
        if (sum > target || pos >= end)
        {
            return;
        }
        cur_state.push_back(candidates[pos]);
        helper(candidates, target, cur_state, pos+1, end, sum+candidates[pos], result);
        cur_state.pop_back();
        while (pos + 1 < end && candidates[pos] == candidates[pos+1])
        {
            pos += 1;
        }
        helper(candidates, target, cur_state, pos+1, end, sum, result);
    }

    static bool cmp(int x, int y)
    {
        return x > y;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        int end = candidates.size();
        if (end == 0)
        {
            return result;
        }
        sort(candidates.begin(), candidates.end(), cmp);
        vector<int> cur_status;
        helper(candidates, target, cur_status, 0, end, 0, result);
        return result;
    }
};