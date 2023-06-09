/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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

    ListNode* reverse(ListNode* head){
        if(head == NULL or head->next == NULL) return head;
        ListNode* curr = head, *prev = NULL;
        while(head){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1 = reverse(l1);
        // l2 = reverse(l2);
        int c = 0;
        ListNode* ans = new ListNode(0), *res = ans;
        while(l1 and l2){
            int a = l1->val+l2->val+c;
            c = a/10;
            ans->next = new ListNode(a%10);
            ans = ans->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int a = l1->val+c;
            c = a/10;
            ans->next = new ListNode(a%10);
            ans = ans->next;
            l1 = l1->next;
        }
        while(l2){
            int a = l2->val+c;
            c = a/10;
            ans->next = new ListNode(a%10);
            ans = ans->next;
            l2 = l2->next;
        }
        if(c){
            ans->next = new ListNode(c);
            ans = ans->next;
        }
        return res->next;
    }

};
// @lc code=end

