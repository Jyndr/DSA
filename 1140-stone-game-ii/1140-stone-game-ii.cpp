class Solution {
public:
    int dp[101][2][101];
    int f(int index, bool alice, int m, vector<int>& piles, int n) {
        if (index == n) {
            return 0;
        }

        if (dp[index][alice][m] != -1) {
            return dp[index][alice][m];
        }

        int ans;

        if (alice) {
            ans = INT_MIN;
            int stones = 0;
            for (int x = 0; x < 2 * m; x++) {
                if (index + x < n) {
                    stones += piles[index + x];
                    ans = max(ans, stones + f(index + x + 1, false,
                                              max(m, x + 1), piles, n));
                } else {
                    break;
                }
            }
        } else {
            ans = INT_MAX;
            for (int x = 0; x < 2 * m; x++) {
                if (index + x < n) {
                    ans = min(ans,
                              f(index + x + 1, true, max(m, x + 1), piles, n));
                } else {
                    break;
                }
            }
        }
        return dp[index][alice][m] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        return f(0, true, 1, piles, piles.size());
    }
};