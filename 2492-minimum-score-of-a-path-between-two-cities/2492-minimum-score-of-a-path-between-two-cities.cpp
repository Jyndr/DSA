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
        if (u == parent[u]) {
            return u;
        }
        return parent[u] = ultimate_p(parent[u]);
    }

    void union_by_size(int u, int v) {
        int ulp_u = ultimate_p(u);
        int ulp_v = ultimate_p(v);

        if (ulp_u == ulp_v) {
            return;
        }

        if (sizee[ulp_u] > sizee[ulp_v]) {
            parent[ulp_v] = ulp_u;
            sizee[ulp_u] += sizee[ulp_v];
        } else {
            parent[ulp_u] = ulp_v;
            sizee[ulp_v] += sizee[ulp_u];
        }
    }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        DSU tree(n + 1);

        vector<int> ans(n + 1, INT_MAX);
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];

            int p1 = tree.ultimate_p(u);
            int p2 = tree.ultimate_p(v);
            tree.union_by_size(u, v);
            int p = tree.ultimate_p(u);

            ans[p] = min({ans[p], wt, ans[p1], ans[p2]});
        }

        return ans[tree.ultimate_p(n)];
    }
};