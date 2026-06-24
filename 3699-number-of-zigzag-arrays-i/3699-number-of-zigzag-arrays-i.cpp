#define ll long long
const int mod = 1e9 + 7;
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        ll dp[n + 1][m + 1][2];
        memset(dp, 0, sizeof(dp));

        // base case
        for (int prev = 1; prev <= m; prev++) {
            dp[n][prev][1] = 1;
            dp[n][prev][0] = 1;
        }

        for (int i = n - 1; i >= 1; i--) {

            vector<ll> cumsum0(m + 1);
            vector<ll> cumsum1(m + 1);

            for (int val = 1; val <= m; val++) {
                cumsum0[val] = ( cumsum0[val - 1] + dp[i + 1][val][0] ) % mod;
                cumsum1[val] = ( cumsum1[val - 1] + dp[i + 1][val][1] ) % mod;
            }

            for (int prev = 1; prev <= m; prev++) {
                dp[i][prev][0] = cumsum1[prev - 1];
                dp[i][prev][1] = (cumsum0[m] - cumsum0[prev] + mod) % mod;
            }
        }

        ll ans = 0;
        for (int prev = 1; prev <= m; prev++) {
            ans = (ans + dp[1][prev][0] + dp[1][prev][1]) % mod;
        }

        return ans;
    }
};