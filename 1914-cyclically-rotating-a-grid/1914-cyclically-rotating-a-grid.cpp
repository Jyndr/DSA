class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m));

        for (int i = 0; i < min(n, m) / 2; i++) {
            vector<int> temp;
            for (int row = i; row < n - 1 - i; row++) {
                temp.push_back(grid[row][i]);
            }
            for (int col = i; col < m - 1 - i; col++) {
                temp.push_back(grid[n - 1 - i][col]);
            }
            for (int row = n - 1 - i; row > i; row--) {
                temp.push_back(grid[row][m - 1 - i]);
            }
            for (int col = m - 1 - i; col > i; col--) {
                temp.push_back(grid[i][col]);
            }

            vector<int> rotated(temp.size());
            int s = temp.size();
            for (int j = 0; j < temp.size(); j++) {
                rotated[(j + k) % s] = temp[j];
            }
            reverse(rotated.begin(), rotated.end());

            for (int row = i; row < n - 1 - i; row++) {
                ans[row][i] = rotated.back();
                rotated.pop_back();
            }
            for (int col = i; col < m - 1 - i; col++) {
                ans[n - 1 - i][col] = rotated.back();
                rotated.pop_back();
            }
            for (int row = n - 1 - i; row > i; row--) {
                ans[row][m - 1 - i] = rotated.back();
                rotated.pop_back();
            }
            for (int col = m - 1 - i; col > i; col--) {
                ans[i][col] = rotated.back();
                rotated.pop_back();
            }
        }
        return ans;
    }
};