/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size(), ans = 0;
        stack<int> st;
        // curr wale bar ke pehle ke sab lambe lamde ka game khatam kro
        // jis bar pe ho usse pehle walo ke saath woh kitna pani bhar sakta dekh lo
        for(int i = 0; i<n; i++){
            while(!st.empty() and h[st.top()]<h[i]){
                
                int popped_height = h[st.top()]; st.pop();
                if(st.empty()) break;

                int dis = i - st.top() - 1;
                int height = min(h[i], h[st.top()]) - popped_height;
                ans+= (height*dis);
            }
            st.push(i);
        }
        return ans;
    }
};
// @lc code=end

