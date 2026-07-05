#define ll long long
class Solution {
public:
    const int mod = 1e9 + 7;

    pair<ll, ll> dp[101][101];
    int vis[101][101];

    void compare(pair<ll, ll>& it, ll& ways, ll& ans, ll a) {
        if (it.first + a > ans) {
            ans = it.first + a;
            ways = it.second;
        } else if (it.first + a == ans) {
            ways = (ways + it.second) % mod;
        }
    }

    pair<ll, ll> f(int i, int j, vector<string>& board) {
        if (i == 0 && j == 0) {
            return {0, 1};
        }

        if (vis[i][j] != 0) {
            return dp[i][j];
        }

        ll ans = INT_MIN;
        ll ways = 0;

        int a = 0;
        if (board[i][j] - '0' >= 0 && board[i][j] - '0' <= 9) {
            a = board[i][j] - '0';
        }

        if (j - 1 >= 0 && board[i][j - 1] != 'X') {
            auto it = f(i, j - 1, board);
            compare(it, ways, ans, a);
        }

        if (i - 1 >= 0 && board[i - 1][j] != 'X') {
            auto it = f(i - 1, j, board);
            compare(it, ways, ans, a);
        }

        if (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] != 'X') {
            auto it = f(i - 1, j - 1, board);
            compare(it, ways, ans, a);
        }

        vis[i][j] = 1;
        return dp[i][j] = {ans, ways};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();

        memset(vis, 0, sizeof(vis));

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = {0, 0};
            }
        }

        auto it = f(n - 1, n - 1, board);

        if (it.first < 0) {
            return {0, 0};
        }

        return {(int)it.first, (int)it.second};
    }
};