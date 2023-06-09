/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    ListNode* start;
    bool compare(ListNode* slow){
        if(slow == NULL) return true;
        if(compare(slow->next) and start->val == slow->val){
            start = start->next;
            return true;
        }
        return false;
    }


    bool isPalindrome(ListNode* head) {
        if(!head or !head->next) return true;
        ListNode* slow = head, *fast = head;
        start = head;
        while(fast){
            slow = slow->next;
            if(fast->next) fast = fast->next->next;
            else fast = fast->next;
        }
        return compare(slow);
    }
};
// @lc code=end

