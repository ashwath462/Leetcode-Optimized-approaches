/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i<n; i++){
            int l = 0, r = n-1;
            while(l<r) swap(matrix[i][l++], matrix[i][r--]);
        }
        return;
    }
};
// @lc code=end

