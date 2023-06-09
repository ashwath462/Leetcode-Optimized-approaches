/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int ind, int k) {
        // int n = nums.size();
        // vector<pair<long,long>> vec(n);
        // for(int i = 0; i<n; i++){
        //     vec[i].first = nums[i];
        //     vec[i].second = i;
        // }
        // sort(vec.begin(),vec.end());
        // for(int i = 0; i<n; i++){
        //     for(int j = i+1 ;j<n; j++){
        //         if(abs(vec[i].first + vd >= vec[j].first)){  
        //             if(abs(vec[i].second - vec[j].second) <= id) return true;
        //         }
        //         else break;
        //     }
        // }
        // return false;

        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i = 0; i<n; i++){
            int b = nums[i]/(k+1);
            if(nums[i]<0) b--;
            // buckets [....-3,-2,-1,0,1,2,3,....];
            // window slide hogi buckets update hongi, jab bhi mp.size()>k hua toh yahi k se zyada bucket toh remove the (i-k)th wala.
            // negative quotient mai -1 hoga bcz 0 pe colision ho jayega aise toh (-1/4, -2/4) aise mai, isleye -- kro, taki -1 se start ho neg.
            if(mp.find(b)!=mp.end()) return true;
            else{
                if(mp.find(b-1) != mp.end() and nums[i] - mp[b-1] <= k) return true;
                if(mp.find(b+1) != mp.end() and mp[b+1] - nums[i] <= k) return true;
                mp[b] = nums[i];
                if(mp.size()>ind){
                    int rem = nums[i-ind]/(k+1);
                    if(nums[i-ind]<0) rem--;
                    mp.erase(rem);
                }
            }
        }
        return false;
    }
};
// @lc code=end

