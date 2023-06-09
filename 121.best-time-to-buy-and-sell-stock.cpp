/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0], ans = 0, n = prices.size();
        for(int i = 1; i<n; i++){
            mini = min(prices[i], mini);
            ans = max(ans,prices[i] - mini);
        }
        return ans;
    }
};
// @lc code=end

