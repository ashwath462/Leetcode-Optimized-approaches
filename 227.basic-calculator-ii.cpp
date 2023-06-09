/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        char sign = '+';
        long long res = 0, num = 0;
        for (int i = 0; i < s.size(); i++) {
            if(isdigit(s[i])) num = 10*num + s[i]-'0';
            if(!isdigit(s[i]) && !isspace(s[i]) || i == s.size()-1) {
                if(sign == '-') st.push(-num);
                else if(sign == '+') st.push(num);
                else{
                    if(sign == '*') num = st.top()*num;
                    else num = st.top()/num;
                    st.pop();
                    st.push(num);
                } 
                sign = s[i];
                num = 0;
            }
        }
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};
// @lc code=end

