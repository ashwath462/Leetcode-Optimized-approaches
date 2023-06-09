/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int n = s.size(), ans = 1, st = 0, e = 0;
        // vector<vector<bool>> dp(n+1,vector<bool>(n+1));
        bool dp[1001][1001];
        for(int i = 0; i<n; i++) dp[i][i] = 1;
        for(int len = 1; len<n; len++){
            for(int i = 0, j = len; i<n and j<n; i++,j++){
                // cout<<i<<" "<<j<<endl;
                if(s[i] == s[j]){
                    if(len == 1 and dp[i][j-1] == 1){
                        dp[i][j] = 1;
                        if(j-i+1 > ans){
                            ans = j-i+1;
                            st = i;
                            e = j;
                        }
                    }
                    else if(dp[i+1][j-1] == 1){
                        dp[i][j] = 1;
                        if(j-i+1 > ans){
                            ans = j-i+1;
                            st = i;
                            e = j;
                        }
                    }
                    else dp[i][j] = 0;
                }
                else dp[i][j] = 0;
            }
        }
        while(st<=e){
            res+= s[st++];
        }
        return res;
    }
};
// @lc code=end

