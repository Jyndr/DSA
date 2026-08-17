class Solution {
public:
    int dp[501][501];
    int f(int left, int right, vector<int>& stoneValue) {
        if (left == right) {
            return 0;
        }

        int ans = 0;
        int sum = 0;

        if (dp[left][right] != -1) {
            return dp[left][right];
        }

        for (int i = left; i <= right; i++) {
            sum += stoneValue[i];
        }

        int prefix_sum = 0;
        for (int i = left; i < right; i++) {
            prefix_sum += stoneValue[i];     // first part sum
            int rest_sum = sum - prefix_sum; // next part sum

            if (prefix_sum > rest_sum) {
                // first part will be thrown away
                ans = max(ans, rest_sum + f(i + 1, right, stoneValue));
            } else if (prefix_sum < rest_sum) {
                // next part will be thrown away
                ans = max(ans, prefix_sum + f(left, i, stoneValue));
            } else {
                ans = max(ans, prefix_sum + f(left, i, stoneValue));
                ans = max(ans, rest_sum + f(i + 1, right, stoneValue));
            }
        }

        return dp[left][right] = ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        memset(dp, -1, sizeof(dp));
        return f(0, n - 1, stoneValue);
    }
};