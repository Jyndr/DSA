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

    void union_by_size(int u, int v) {
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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {

        DSU tree(n);
        int i = 0, j = 0;

        while (j < n) {
            while (j < n && abs(nums[i] - nums[j]) <= maxDiff) {
                tree.union_by_size(i, j);
                j++;
            }
            i++;
        }

        vector<bool> ans;
        for (int i = 0; i < queries.size(); i++) {
            int u = queries[i][0];
            int v = queries[i][1];

            ans.push_back(tree.ultimate_p(u) == tree.ultimate_p(v));
        }

        return ans;
    }
};