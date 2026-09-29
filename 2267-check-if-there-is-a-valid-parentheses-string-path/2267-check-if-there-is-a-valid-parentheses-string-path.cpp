class Solution {
public:
    int dp[101][101][202];
    bool f(int i, int j, int cnt, vector<vector<char>>& grid) {
        if (grid[i][j] == '(') {
            cnt++;
        } else {
            cnt--;
        }

        if (cnt < 0) {
            return false;
        }

        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return cnt == 0;
        }

        if (dp[i][j][cnt] != -1) {
            return dp[i][j][cnt];
        }

        bool ans = false;
        if (j + 1 < grid[0].size()) { // right
            ans |= f(i, j + 1, cnt, grid);
        }
        if (i + 1 < grid.size()) { // down
            ans |= f(i + 1, j, cnt, grid);
        }
        return dp[i][j][cnt] = ans;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        memset(dp, -1, sizeof(dp));
        return f(0, 0, 0, grid);
    }
};