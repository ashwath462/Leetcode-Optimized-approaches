/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int n;
    vector<int> dp;
    int solve(int i, vector<int>& nums){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = max(solve(i+1,nums), nums[i]+solve(i+2,nums));
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        dp.resize(n+1,-1);
        return solve(0,nums);
    }
};
// @lc code=end

