class Solution {
public:
    int f(int i, int j, int xorr, vector<vector<int>>& grid,
          vector<vector<vector<int>>>& dp) {
        int curr_xor = xorr ^ grid[i][j];
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return curr_xor;
        }

        if(dp[i][j][xorr] != -1){
            return dp[i][j][xorr];
        }

        int ans = INT_MAX;

        // moving right
        if (i + 1 < grid.size()) {
            ans = min(ans, f(i + 1, j, curr_xor, grid, dp));
        }

        // moving down
        if (j + 1 < grid[0].size()) {
            ans = min(ans, f(i, j + 1, curr_xor, grid, dp));
        }

        return dp[i][j][xorr] = ans;
    }

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(1024, -1)));
        return f(0, 0, 0, grid, dp);
    }
};