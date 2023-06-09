/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> vis;
        for(auto it : wordList) vis[it] = 0;
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            auto it = q.front(); q.pop();
            if(it.first == endWord) return it.second;
            for(int i = 0; i<it.first.size(); i++){
                string tmp = it.first;
                for(char a = 'a'; a<='z'; a++){
                    tmp[i] = a;
                    if(vis.find(tmp) != vis.end()){
                        vis.erase(tmp);
                        q.push({tmp,it.second+1});
                    }
                }
            }
        }
        return 0;
    }
};
// @lc code=end

