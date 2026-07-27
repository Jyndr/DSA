#define ll long long
class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& penalty) {

        ll row = m, col = n;

        priority_queue<pair<ll, pair<int, int>>,
                       vector<pair<ll, pair<int, int>>>,
                       greater<pair<ll, pair<int, int>>>>
            pq;

        vector<vector<vector<ll>>> dp(
            row + 1, vector<vector<ll>>(col + 1, vector<ll>(2, LLONG_MAX)));

        pq.push({1, {0, 1}});
        dp[0][0][1] = 1;

        while (!pq.empty()) {
            ll dis = pq.top().first;
            int node = pq.top().second.first;
            int parity = pq.top().second.second;
            pq.pop();

            if (node == (row - 1) * col + col - 1) {
                return dis;
            }

            int nrow = node / col;
            int ncol = node % col;

            if (parity) {             // odd
                if (ncol + 1 < col) { // right
                    if (dp[nrow][ncol + 1][0] > dis + (nrow + 1) * (ncol + 2)) {
                        dp[nrow][ncol + 1][0] = dis + (nrow + 1) * (ncol + 2);
                        pq.push({dp[nrow][ncol + 1][0],
                                 {nrow * col + ncol + 1, 0}});
                    }
                }
                if (nrow + 1 < row) { // down
                    if (dp[nrow + 1][ncol][0] > dis + (nrow + 2) * (ncol + 1)) {
                        dp[nrow + 1][ncol][0] = dis + (nrow + 2) * (ncol + 1);
                        pq.push({dp[nrow + 1][ncol][0],
                                 {(nrow + 1) * col + ncol, 0}});
                    }
                }
                if (nrow - 1 >= 0) { // up with penalty
                    if (dp[nrow - 1][ncol][0] >
                        dis + penalty[nrow][ncol] + nrow * (ncol + 1)) {
                        dp[nrow - 1][ncol][0] =
                            dis + penalty[nrow][ncol] + nrow * (ncol + 1);
                        pq.push({dp[nrow - 1][ncol][0],
                                 {(nrow - 1) * col + ncol, 0}});
                    }
                }
                if (ncol - 1 >= 0) { // left with penalty
                    if (dp[nrow][ncol - 1][0] >
                        dis + penalty[nrow][ncol] + (nrow + 1) * (ncol)) {
                        dp[nrow][ncol - 1][0] =
                            dis + penalty[nrow][ncol] + (nrow + 1) * (ncol);
                        pq.push({dp[nrow][ncol - 1][0],
                                 {nrow * col + ncol - 1, 0}});
                    }
                }
            } else {                  // even
                if (ncol + 1 < col) { // right with penalty
                    if (dp[nrow][ncol + 1][1] >
                        penalty[nrow][ncol] + dis + (nrow + 1) * (ncol + 2)) {
                        dp[nrow][ncol + 1][1] =
                            dis + penalty[nrow][ncol] + (nrow + 1) * (ncol + 2);
                        pq.push({dp[nrow][ncol + 1][1],
                                 {nrow * col + ncol + 1, 1}});
                    }
                }
                if (nrow + 1 < row) { // down with penalty
                    if (dp[nrow + 1][ncol][1] >
                        dis + penalty[nrow][ncol] + (nrow + 2) * (ncol + 1)) {
                        dp[nrow + 1][ncol][1] =
                            dis + penalty[nrow][ncol] + (nrow + 2) * (ncol + 1);
                        pq.push({dp[nrow + 1][ncol][1],
                                 {(nrow + 1) * col + ncol, 1}});
                    }
                }
                if (nrow - 1 >= 0) { // up
                    if (dp[nrow - 1][ncol][1] > dis + nrow * (ncol + 1)) {
                        dp[nrow - 1][ncol][1] = dis + nrow * (ncol + 1);
                        pq.push({dp[nrow - 1][ncol][1],
                                 {(nrow - 1) * col + ncol, 1}});
                    }
                }
                if (ncol - 1 >= 0) { // left
                    if (dp[nrow][ncol - 1][1] > dis + (nrow + 1) * (ncol)) {
                        dp[nrow][ncol - 1][1] = dis + (nrow + 1) * (ncol);
                        pq.push({dp[nrow][ncol - 1][1],
                                 {nrow * col + ncol - 1, 1}});
                    }
                }
            }
            if (dp[nrow][ncol][!parity] > dis + penalty[nrow][ncol]) {
                dp[nrow][ncol][!parity] = dis + penalty[nrow][ncol];
                pq.push({dp[nrow][ncol][!parity], {node, !parity}});
            }
        }
        return 0;
    }
};