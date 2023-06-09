/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* h1 = headA;
        while(h1->next) h1 = h1->next;
        h1->next = headA;

        ListNode *slow = headB, *fast = headB;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                slow = headB;
                while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                h1->next = NULL;
                return slow;
            }
        }
        h1->next = NULL;
        return NULL;
    }
};
// @lc code=end

