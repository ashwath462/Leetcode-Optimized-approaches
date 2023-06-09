/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        // vector<int> arr(n,0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i = 0; i<n; i++){
            if(lists[i] != NULL)pq.push({lists[i]->val,i});
        }
        ListNode* res = new ListNode(0), *ans = res;
        while(!pq.empty()){
            auto it = pq.top(); pq.pop();
            res->next = new ListNode(it.first);
            res = res->next;
            lists[it.second] = lists[it.second]->next;
            if(lists[it.second] != NULL) pq.push({lists[it.second]->val,it.second});
        }
        return ans->next;
    }
};
// @lc code=end

