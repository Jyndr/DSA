class Solution {
public:
    int mod = 1e9 + 7;
    int dp[1001][1001][2];
    int f(int i, int k, bool atleast_1, int n) {
        if (i == n) {
            return k == 0 && !atleast_1;
        }

        if( dp[i][k][atleast_1]!= -1){
            return  dp[i][k][atleast_1];
        }
        int ans = 0;

        if (!atleast_1) {
            ans = (ans + f(i + 1, k, true, n)) % mod;  // taking
            ans = (ans + f(i + 1, k, false, n)) % mod; // not taking
        } else {
            if (k - 1 >= 0) {
                ans = (ans + f(i, k - 1, false, n)) % mod; // taking and ending
            }
            ans = (ans + f(i + 1, k, true, n)) % mod; // taking and continue;
        }

        return dp[i][k][atleast_1] = ans;
    }
    int numberOfSets(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return f(0, k, false, n);
    }
};