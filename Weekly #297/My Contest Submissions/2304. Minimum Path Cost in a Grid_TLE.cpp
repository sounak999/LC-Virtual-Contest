/* TLE Solution (submitted in the contest) */
class Solution {
    int solve(vector<vector<int>>& grid, vector<vector<int>>& moveCost, int i, int j, int row, int col)
    {
        if(i == row-1)
        {
            return grid[i][j];
        }
        
        int ans = INT_MAX;
        for(int k = 0; k < col; k++)
        {
            int rowIdx = grid[i][j], colIdx = k;
            ans = min(ans, grid[i][j] + moveCost[rowIdx][colIdx] + solve(grid, moveCost, i+1, k, row, col));
        }
        
        return ans;
    }
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        int i = 0, j = 0, sum = INT_MAX, curr = 0;
        
        for(int i=0; i<n; i++)
        {
            sum = min(sum, solve(grid, moveCost, 0, i, m, n));
        }
        
        return sum;
    }
};