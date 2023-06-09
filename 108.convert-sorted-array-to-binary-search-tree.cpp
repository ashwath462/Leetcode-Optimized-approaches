/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
class Solution {
public:
    TreeNode* solve(int i, int j, vector<int>& nums){
        if(i<0 or j>=nums.size() or j<i) return NULL;
        int n = j-i+1, m = (j+i)/2;
        // cout<<i<<" "<<j<<" "<<nums[m]<<endl;
        if(n == 0) return NULL;
        if(n == 1) return new TreeNode(nums[m]);
        TreeNode* root = new TreeNode(nums[m]);
        root->left = solve(i,m-1,nums);
        root->right = solve(m+1,j,nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return solve(0,n-1,nums);
    }
};
// @lc code=end

