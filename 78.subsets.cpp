/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
    int n;
    vector<vector<int>> ans;
public:
    void solve(vector<int> &nums, int ind, vector<int> &tmp){
        if(ind==n){
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(nums[ind]);
        solve(nums,ind+1,tmp);
        tmp.pop_back();
        solve(nums,ind+1,tmp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> tmp;
        solve(nums,0,tmp);
        return ans;
    }
};
// @lc code=end

