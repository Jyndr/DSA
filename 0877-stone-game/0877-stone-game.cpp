class Solution {
public:
    int dp[501][501][2];
    int f(int i, int j, int parity, vector<int>& piles) {
        if (i > j) {
            return 0;
        }

        if (dp[i][j][parity] != INT_MIN) {
            return dp[i][j][parity];
        }

        if (parity) { // alice
            return dp[i][j][1] = max(piles[i] + f(i + 1, j, 0 , piles),
                                     piles[j] + f(i, j - 1, 0 , piles));
        } else {
            return dp[i][j][0] = min(f(i + 1, j, 1 , piles) - piles[i],
                                     f(i, j - 1, 1 , piles) - piles[j]);
        }
        return 0;
    }
    bool stoneGame(vector<int>& piles) {
        for (int i = 0; i < piles.size(); i++) {
            for (int j = 0; j < piles.size(); j++) {
                for (int k = 0; k <= 1; k++) {
                    dp[i][j][k] = INT_MIN;
                }
            }
        }
        int ans = f(0, piles.size() - 1, 1 , piles);
        return ans > 0;
    }
};