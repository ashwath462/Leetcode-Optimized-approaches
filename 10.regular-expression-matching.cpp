/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
class Solution {
public:
    int n,m;
    string s,p;
    vector<vector<int>> dp;
    bool solve(int i, int j){
        if(i>=n and j>=m) return true;
        if(j>=m) return false;
        if(dp[i][j] != -1) return dp[i][j];
        bool match = ((i<n) and (s[i] == p[j] || p[j] == '.'));
        if(j+1<m and p[j+1] == '*'){
            return dp[i][j] = (solve(i,j+2)) || (match && solve(i+1,j));
        }
        if(match) return dp[i][j] = solve(i+1,j+1);
        return false;
    }
    
    
    bool isMatch(string s, string p) {
        this->s = s, this->p = p;
        n = s.size(), m = p.size();
        dp.resize(n+1, vector<int>(m+1,-1));
        return solve(0,0);
    }
};
// @lc code=end

