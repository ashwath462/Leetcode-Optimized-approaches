/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // xor of any two same no gives 0;
        int ans = 0;
        for(auto it : nums) ans ^= it;
        return ans;
    }
};
// @lc code=end

