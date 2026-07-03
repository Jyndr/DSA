#define ll long long
class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges,
                                      int power, vector<int>& cost, int source,
                                      int target) {

        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int t = edges[i][2];
            adj[u].push_back({v, t});
        }

        vector<vector<ll>> vis(n, vector<ll>(power + 1, LLONG_MAX));

        priority_queue<pair<pair<ll, ll>, int>, vector<pair<pair<ll, ll>, int>>,
                       greater<pair<pair<ll, ll>, int>>>
            pq;

        pq.push({{0, 0}, source});
        vis[source][0] = 0;

        while (!pq.empty()) {
            auto i = pq.top();
            pq.pop();

            int node = i.second;
            ll tt = i.first.first;
            ll p = i.first.second;

            for (auto it : adj[node]) {
                int new_node = it.first;
                int new_time = it.second;
                if (p + cost[node] <= power &&
                    vis[new_node][p + cost[node]] > tt + new_time) {
                    vis[new_node][p + cost[node]] = tt + new_time;
                    pq.push({{tt + new_time, p + cost[node]}, new_node});
                }
            }
        }

        ll time = LLONG_MAX;
        ll pow = -1;

        for (int i = 0; i <= power; i++) {
            if (vis[target][i] < time) {
                time = vis[target][i];
                pow = power - i;
            }
        }

        if (time == LLONG_MAX) {
            return {-1, -1};
        }
        return {time, pow};
    }
};