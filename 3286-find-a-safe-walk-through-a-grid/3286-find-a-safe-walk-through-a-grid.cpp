class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int m = grid.size();
        int n = grid[0].size();

        priority_queue<pair<int, int>, vector<pair<int, int>>,
        greater<pair<int, int>>>pq;

        vector<int> vis(n * m, 0);
        vis[0] = 1;
        pq.push({grid[0][0], 0});

        int delr[4] = {-1, 0, 1, 0};
        int delc[4] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int node = it.second;
            int dis = it.first;

            int row = node / n;
            int col = node % n;

            if (row == m - 1 && col == n - 1) {
                return health - dis >= 1;
            }

            for (int d = 0; d < 4; d++) {
                int newr = row + delr[d];
                int newc = col + delc[d];

                if (newr >= 0 && newc >= 0 && newr < m && newc < n &&
                    vis[newr * n + newc] == 0) {
                    vis[newr * n + newc] = 1;
                    pq.push({dis + grid[newr][newc], newr * n + newc});
                }
            }
        }

        return false;
    }
};