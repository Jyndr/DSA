class Solution {
public:
    const int delr[4] = {-1, 0, 1, 0};
    const int delc[4] = {0, -1, 0, 1};

    vector<int> bfs(int n, vector<vector<int>>& grid) {
        vector<int> dis(n * n, INT_MAX);
        queue<int> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) { // taking all thieves as the root
                    q.push(i * n + j);
                    dis[i * n + j] = 0;
                }
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            int row = node / n;
            int col = node % n;

            for (int i = 0; i < 4; i++) {
                int newr = delr[i] + row;
                int newc = delc[i] + col;

                if (newr >= 0 && newr < n && newc >= 0 && newc < n) {
                    if (dis[node] + 1 < dis[newr * n + newc]) {
                        dis[newr * n + newc] = 1 + dis[node];
                        q.push(newr * n + newc);
                    }
                }
            }
        }
        return dis;
    }

    bool dfs(vector<vector<int>>& grid, int v, vector<int>& dis, int i, int j,
             vector<vector<int>>& vis) {

        int n = grid.size();
        if (i == n - 1 && j == n - 1) {
            return dis[i * n + j] >= v;
        }

        if (i == 0 && j == 0 && dis[i * n + j] < v) {
            return false;
        }

        vis[i][j] = 1;

        bool ans = false;
        for (int d = 0; d < 4; d++) {
            int newr = i + delr[d];
            int newc = j + delc[d];

            if (newr < n && newc < n && newr >= 0 && newc >= 0 &&
                vis[newr][newc] == 0 && dis[newr * n + newc] >= v) {
                ans |= dfs(grid, v, dis, newr, newc, vis);
                if (ans == true) {
                    vis[i][j] = 0;
                    return ans;
                }
            }
        }

        return ans;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> dis = bfs(n, grid);

        int low = 0, high = 2 * n;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            vector<vector<int>> vis(n, vector<int>(n, 0));
            
            if (dfs(grid, mid, dis, 0, 0, vis)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};