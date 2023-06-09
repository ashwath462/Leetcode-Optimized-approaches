/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */

// @lc code=start
class Solution {
    int n;
    string start;
    vector<vector<string>> ans;
    unordered_map<string,int> mp;
public:

    void dfs(string &s, vector<string> &tmp){
        cout<<s<<" ";
        if(s == start){
            reverse(tmp.begin(), tmp.end());
            ans.push_back(tmp);
            reverse(tmp.begin(), tmp.end());
            return;
        }
        int step = mp[s];
        // mp.erase(s);
        for(int i = 0; i<s.size(); i++){
            string k = s;
            for(char a = 'a'; a<='z'; a++){
                k[i] = a;
                if(mp.find(k) != mp.end() and mp[k] == step-1){
                    tmp.push_back(k);
                    dfs(k,tmp);
                    tmp.pop_back();
                }
            }
        }
    }


    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        n = 0;
        start = beginWord;
        unordered_map<string,bool> vis;
        for(auto it : wordList) vis[it] = true;
        vis.erase(beginWord);
        queue<pair<string,int>> q;
        mp[beginWord] = 1;
        q.push({beginWord,1});
        while(!q.empty()){
            pair<string,int> it = q.front(); q.pop();
            if(it.first == endWord){
                n = it.second;
                break;
            }
            for(int i = 0; i<it.first.size(); i++){
                char ori = it.first[i];
                for(char a = 'a'; a<='z'; a++){
                    it.first[i] = a;
                    if(vis.find(it.first) != vis.end()){
                        vis.erase(it.first);
                        q.push({it.first,it.second+1});
                        mp[it.first] = it.second+1;
                    }
                }
                it.first[i] = ori;
            }
        }
        if(n!=0){
            vector<string> tmp;
            tmp.push_back(endWord);
            dfs(endWord,tmp);
        }
        return ans;
    }
};
// @lc code=end

