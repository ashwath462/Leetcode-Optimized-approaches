/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> hash(32,0);
        int j = 31;
        while(n){
            hash[j--] = n%2;
            n/=2;
        }
        uint32_t ans = 0;
        for(int i = 0; i<=31; i++){
            if(hash[i]) ans+= round(pow(2,i));
        }
        return ans;
    }
};
// @lc code=end

