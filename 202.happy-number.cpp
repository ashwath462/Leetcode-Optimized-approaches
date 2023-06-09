/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        while(n/10 > 0){
            int sum = 0;
            while(n>0){
                sum += (n%10)*(n%10);
                n = n/10;
            }
            n = sum;
        }
        if(n == 1 || n == 7) return true;
        return false;
    }
};
// @lc code=end

