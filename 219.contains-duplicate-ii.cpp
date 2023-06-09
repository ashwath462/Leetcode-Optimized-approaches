/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i = 0; i<n; i++){
            if(mp.find(nums[i]) != mp.end()){
                if(i-mp[nums[i]] <= k) return true;
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};
// @lc code=end

