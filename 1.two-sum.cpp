/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>> vp;
        for(int i = 0; i<n; i++){
            vp.push_back({nums[i],i});
        }
        sort(vp.begin(), vp.end());
        int i = 0, j = n-1;
        while(i<j){
            int sum = vp[i].first+vp[j].first;
            if(sum==target) return {vp[i].second,vp[j].second};
            if(sum>target) j--;
            else i++;
        }
        return {-1,-1};
    }
};
// @lc code=end

