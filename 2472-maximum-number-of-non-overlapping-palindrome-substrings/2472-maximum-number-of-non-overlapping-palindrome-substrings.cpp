class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> isPalindrome(n + 1, vector<bool>(n + 1, false));

        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                if (j - i <= 1) {
                    isPalindrome[i][j] = (s[i] == s[j]);
                } else {
                    isPalindrome[i][j] =
                        ((s[i] == s[j]) && isPalindrome[i + 1][j - 1]);
                }
            }
        }

        vector<int> dp(n + 1);

        for (int len = k; len <= n; len++) {
            int ans = dp[len - 1];
            int j = len - 1;
            for (int i = 0; i <= j - k + 1; i++) {
                if (isPalindrome[i][j]) {
                    ans = max(ans, 1 + dp[i]);
                }
            }
            dp[len] = ans;
        }
        return dp[n];
    }
};