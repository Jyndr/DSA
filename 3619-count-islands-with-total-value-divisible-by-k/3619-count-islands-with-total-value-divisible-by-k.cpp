class DSU {
public:
    vector<int> parent;
    vector<int> sizee;

    DSU(int n) {
        parent.resize(n);
        sizee.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int ultimate_p(int u) {
        if (parent[u] == u) {
            return u;
        }
        return parent[u] = ultimate_p(parent[u]);
    }

    void merge(int u, int v) {
        int ulp_u = ultimate_p(u);
        int ulp_v = ultimate_p(v);

        if (ulp_u == ulp_v) {
            return;
        }

        if (sizee[ulp_u] > sizee[ulp_v]) {
            sizee[ulp_u] += sizee[ulp_v];
            parent[ulp_v] = ulp_u;
        } else {
            sizee[ulp_v] += sizee[ulp_u];
            parent[ulp_u] = ulp_v;
        }
    }
};

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<long long> sum(n * m);
        DSU dsu(n * m);

        int delr[4] = {-1, 1, 0, 0};
        int delc[4] = {0, 0, -1, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] > 0) {

                    for (int k = 0; k < 4; k++) {
                        int newr = delr[k] + i;
                        int newc = delc[k] + j;

                        if (newr >= 0 && newc >= 0 && newr < n && newc < m &&
                            grid[newr][newc] > 0) {
                            dsu.merge(newr * m + newc, i * m + j);
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum[dsu.ultimate_p(i * m + j)] += 1LL * grid[i][j];
            }
        }

        int cnt = 0;
        for (int i = 0; i < n * m; i++) {
            if (grid[i / m][i % m] > 0 && dsu.ultimate_p(i) == i) {
                cnt += (sum[i] % k == 0);
            }
        }

        return cnt;
    }
};