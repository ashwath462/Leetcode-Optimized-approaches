/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
    int n,m;
public:
    void dfs(int i, int j, vector<vector<char>>& grid){
        if(i>=n or i<0 or j>=m or j<0 or grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        n = grid.size(), m = grid[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == '1'){
                    dfs(i,j,grid);
                    ans++;
                }
                // cout<<grid[i][j]<<" ";
            }
            // cout<<endl;
        } 
        return ans;
    }
};
// @lc code=end

