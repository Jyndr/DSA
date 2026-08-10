class Solution {
public:
    int dp[100001][2];
    bool f(int n, vector<int>& sqr, bool alice) {
        if (n == 0) {
            return !alice;
        }

        if (dp[n][alice] != -1) {
            return dp[n][alice];
        }

        bool ans;

        if (alice) {
            ans = false;
            for (int j = 0; j < sqr.size(); j++) {
                if (sqr[j] <= n) {
                    ans = (ans | f(n - sqr[j], sqr, false));
                } else {
                    break;
                }
            }
        } else {
            ans = true;
            for (int j = 0; j < sqr.size(); j++) {
                if (sqr[j] <= n) {
                    ans = (ans & f(n - sqr[j], sqr, true));
                } else {
                    break;
                }
            }
        }

        return dp[n][alice] = ans;
    }
    bool winnerSquareGame(int n) {
        vector<int> perfect_squares;

        for (int i = 1; i * i <= n; i++) {
            perfect_squares.push_back(i * i);
        }

        memset(dp, -1, sizeof(dp));

        return f(n, perfect_squares, true);
    }
};