/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

typedef long long ll;
class Solution {
public:
    bool isVal(TreeNode* root, ll mini, ll maxi){
        if(!root) return true;
        bool ans = true;
        if(root->val>=maxi or root->val<=mini) return false;
        bool left = isVal(root->left, mini, root->val);
        bool right = isVal(root->right, root->val, maxi);
        return (left && right);
    }
    bool isValidBST(TreeNode* root) {
        return isVal(root,LLONG_MIN, LLONG_MAX);
    }
};
// @lc code=end

