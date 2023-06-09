/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        for(int i = 0; i<n; i++){
            if((s[i] == '(') or (s[i] == '{') or (s[i] == '[')) st.push(s[i]);
            else{
                if(st.empty()) return false;
                if(s[i] == ')' and st.top() == '(') st.pop();
                else if(s[i] == ']' and st.top() == '[') st.pop();
                else if(s[i] == '}' and st.top() == '{') st.pop();
                else return false;
            }
        }
        if(st.size()) return false;
        return true;
    }
};
// @lc code=end

