/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size(), ans = INT_MIN;
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == '1') dp[i][j] = 1;
                if(i>0 and j>0 and mat[i][j] == '1' and mat[i-1][j] == '1' and mat[i][j-1] == '1') dp[i][j] = min({dp[i-1][j-1],dp[i-1][j], dp[i][j-1]})+1;
                ans = max(ans,dp[i][j]);
            }
        }
        return ans*ans;
    }
};
// @lc code=end

