/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */

// @lc code=start
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        for(int i = 0; i<pow(2,n); i++) ans.push_back(i^(i/2));
        return ans;
    }
};
// @lc code=end

