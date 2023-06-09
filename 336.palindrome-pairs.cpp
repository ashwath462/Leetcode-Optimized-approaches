/*
 * @lc app=leetcode id=336 lang=cpp
 *
 * [336] Palindrome Pairs
 */

// @lc code=start
class Solution {
public:
    bool isPal(string s){
        int i = 0, j = s.size()-1;
        while(i<=j){
            if(s[i] != s[j]) return false;
            i++,j--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> mp;
        for(int i = 0; i<n; i++){
            string s = words[i];
            reverse(s.begin(), s.end());
            mp[s] = i;
        }
        vector<vector<int>> ans;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<=words[i].size(); j++){
                string s1 = words[i].substr(0,j);
                string s2 = words[i].substr(j);
                // cout<<s1<<" "<<s2<<endl;
                if(mp.find(s1)!=mp.end() and isPal(s2)){
                    if(mp[s1]!=i) ans.push_back({i,mp[s1]});
                }
                if(s1.size() and mp.find(s2)!=mp.end() and isPal(s1)){
                    if(mp[s2]!=i) ans.push_back({mp[s2],i});
                }
            }
        }
        return ans;
    }
};
// @lc code=end

