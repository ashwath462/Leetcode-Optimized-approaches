/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        int c = 0;
        string ans = "";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int i = 0;
        while(i<num1.size() and i<num2.size()){
            int a = (num1[i] - '0') + (num2[i]-'0') + c;
            // cout<<a<<" ";
            ans += to_string(a%10);
            c = a/10;
            i++;
        }
        while(i<num1.size()){
            int a = (num1[i] - '0') + c;
            // cout<<a<<" ";
            ans += to_string(a%10);
            c = a/10;
            i++;
        }
        while(i<num2.size()){
            int a = (num2[i] - '0') + c;
            // cout<<a<<" ";
            ans += to_string(a%10);
            c = a/10;
            i++;
        }
        if(c) ans+= to_string(c);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

