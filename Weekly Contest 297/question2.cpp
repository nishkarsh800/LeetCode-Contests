/*
Minimum Path Cost in a Grid
Difficulty: Medium
You are given a 0-indexed m x n integer matrix grid consisting of distinct integers from 0 to m * n - 1. You can move in this matrix from a cell to any other cell in the next row. That is, if you are in cell (x, y) such that x < m - 1, you can move to any of the cells (x + 1, 0), (x + 1, 1), ..., (x + 1, n - 1). Note that it is not possible to move from cells in the last row.

Each possible move has a cost given by a 0-indexed 2D array moveCost of size (m * n) x n, where moveCost[i][j] is the cost of moving from a cell with value i to a cell in column j of the next row. The cost of moving from cells in the last row of grid can be ignored.

The cost of a path in grid is the sum of all values of cells visited plus the sum of costs of all the moves made. Return the minimum cost of a path that starts from any cell in the first row and ends at any cell in the last row.



Constraints:

m == grid.length
n == grid[i].length
2 <= m, n <= 50
grid consists of distinct integers from 0 to m * n - 1.
moveCost.length == m * n
moveCost[i].length == n
1 <= moveCost[i][j] <= 100

*/

// Here is the Solution:

class Solution {
public:
    int dp[51][51];
    int helper(vector<vector<int>>& grid, vector<vector<int>>& moveCost, int x, int y){
        if(x==grid.size()-1){
            return grid[x][y];
        }
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        int res=INT_MAX/2;
        for(int index=0;index<grid[0].size();index++){
            int cost=grid[x][y]+moveCost[grid[x][y]][index]+helper(grid,moveCost,x+1,index);
            res=min(res,cost);
        }
        return dp[x][y]=res;
    }
    
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        memset(dp,-1,sizeof(dp));
        int n=grid.size();
        int m=grid[0].size();
        int res=INT_MAX/2;
        for(int i=0;i<m;i++){
            res=min(res,helper(grid,moveCost,0,i));
        }
        return res;
    }
};