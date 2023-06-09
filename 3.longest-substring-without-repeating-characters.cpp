/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        map<char,int> arr;
        int i = 0, j = 0, ans = 0;
        while(j<n){
            if(arr[s[j]] >= 1){
                arr[s[i]]--;
                i++;
            }
            else{
                arr[s[j]]++;
                j++;
            }
            ans = max(ans,j-i);
        }
        return ans;
    }
};
// @lc code=end

