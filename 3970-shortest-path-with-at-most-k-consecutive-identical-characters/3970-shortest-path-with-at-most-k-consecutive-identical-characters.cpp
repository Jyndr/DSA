class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }

        vector<vector<int>> vis(n, vector<int>(k + 1, INT_MAX));

        priority_queue<pair<pair<int, int>, int>,
                       vector<pair<pair<int, int>, int>>,
                       greater<pair<pair<int, int>, int>>>
            pq;

        pq.push({{0, 1}, 0});
        vis[0][1] = 0;
        int ans = INT_MAX;

        while (!pq.empty()) {
            auto i = pq.top();
            pq.pop();

            int d = i.first.first;
            int c = i.first.second;
            int node = i.second;

            if (node == n - 1) {
                ans = min(ans, d);
            }

            for (auto it : adj[node]) {
                int new_node = it.first;
                int new_d = d + it.second;
                int new_c = c + 1;
                if (labels[new_node] != labels[node]) {
                    new_c = 1;
                }

                if (new_c > k) {
                    continue;
                }

                if (vis[new_node][new_c] > new_d) {
                    pq.push({{new_d, new_c}, new_node});
                    vis[new_node][new_c] = new_d;
                }
            }
        }

        if (ans == INT_MAX) {
            return -1;
        }
        return ans;
    }
};