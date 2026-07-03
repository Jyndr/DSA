#define ll long long
class Solution {
public:
    bool check(ll mid, vector<vector<pair<int, int>>>& adj, ll k) {

        priority_queue<pair<ll, int>, vector<pair<ll, int>>,
                       greater<pair<ll, int>>>
            pq;

        vector<long long> vis(adj.size(), LLONG_MAX);
        pq.push({0, 0});
        vis[0] = 0;

        while (!pq.empty()) {
            auto i = pq.top();
            pq.pop();

            int node = i.second;
            ll dis = i.first;

            if (dis > vis[node]) {
                continue;
            }

            if (node == adj.size() - 1) {
                return true;
            }

            for (auto it : adj[node]) {
                if (it.second < mid) {
                    continue;
                }
                if (vis[node] + it.second < vis[it.first] &&
                    vis[node] + it.second <= k) {
                    vis[it.first] = it.second + vis[node];
                    pq.push({dis + it.second, it.first});
                }
            }
        }
        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                         long long k) {

        vector<vector<pair<int, int>>> adj(online.size());
        int low = INT_MAX, high = INT_MIN;

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            if (online[u] && online[v]) {
                adj[u].push_back({v, wt});
                low = min(low, wt);
                high = max(high, wt);
            }
        }

        int ans = -1;

        while (low <= high) {
            ll mid = low + (high - low) / 2;

            if (check(mid, adj, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};