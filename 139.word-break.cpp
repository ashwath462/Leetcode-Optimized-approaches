/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
    int n,m;
    unordered_map<string, int> mp;
    vector<int> dp;
public:

    bool solve(string &s, int i){
        if(i>=n) return true;
        if(dp[i]!=-1) return dp[i];
        string t = "";
        bool ans = false;
        for(int j = i; j<n; j++){
            t+=s[j];
            if(mp.find(t)!=mp.end()){
                ans |= solve(s,j+1);
            }
        }
        return dp[i] = ans;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length(), m = wordDict.size();
        for(int i = 0; i<m; i++) mp[wordDict[i]]++;
        dp.resize(n+1,-1);
        return solve(s,0);
    }
};
// @lc code=end

