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
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        DSU tree(n);

        vector<int> edge(n);
        vector<int> nodes_in_component(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            tree.union_by_size(u, v);
            edge[u]++;
            edge[v]++;
        }

        for (int i = 0; i < n; i++) {
            nodes_in_component[tree.parent[i]]++;
        }

        vector<bool> is_completed(n, true);

        for (int i = 0; i < n; i++) {
            int p = tree.parent[i];
            int req = nodes_in_component[p] - 1;
            is_completed[p] = is_completed[p] && (edge[i] == req);
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            cnt += (tree.parent[i] == i && is_completed[i]);
        }

        return cnt;
    }
};