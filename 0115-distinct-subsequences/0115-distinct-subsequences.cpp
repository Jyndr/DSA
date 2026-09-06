class Solution {
public:
    int mod = 1e9 + 7;
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][m] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s[i] == t[j]) { // taking
                    dp[i][j] = (dp[i][j] + dp[i + 1][j + 1]) % mod;
                    dp[i][j] = (dp[i][j] + dp[i + 1][j]) % mod;
                } else { // not taking
                    dp[i][j] = (dp[i][j] + dp[i + 1][j]) % mod;
                }
            }
        }

        return dp[0][0];
    }
};