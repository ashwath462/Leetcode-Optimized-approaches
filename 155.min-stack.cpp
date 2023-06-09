/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */



// @lc code=start
typedef long long ll;

class MinStack {
public:
    ll mini = INT_MAX;
    stack<int> st;
    MinStack() {
        
    }
    
    void push(int val) {
        ll curr = val;
        if(st.empty()){
            mini = curr;
            st.push(curr);
            return;
        }
        if(curr<mini){
            st.push(2*curr - mini);
            mini = curr;
        }
        else st.push(curr);
    }
    
    void pop() {
        ll t = st.top(); st.pop();
        if(t>=mini) return;
        else{
            mini = 2*mini - t;
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        return st.top();
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

