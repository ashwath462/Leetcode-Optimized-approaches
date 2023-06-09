/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i<n-2; i++){
            if(i>0 and nums[i] == nums[i-1]) continue;
            int j = i+1, k = n-1, a = nums[i];
            while(j<k){
                int b = nums[j], c = nums[k];
                if(a+b+c == 0){
                    ans.push_back({a,b,c});
                    while(j<k and nums[j] == b) j++;
                    while(k>j and nums[k] == c) k--;
                }
                if(b+c < (-a)) while(j<k and nums[j] == b) j++;
                else while(k>j and nums[k] == c) k--;
            }
        }
        return ans;
    }
};
// @lc code=end

