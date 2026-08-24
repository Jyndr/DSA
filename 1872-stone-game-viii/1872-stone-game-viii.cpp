class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {

        int n = stones.size();
        vector<int>prefixSum(n);
        prefixSum[0] = stones[0];

        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + stones[i];
        }

        vector<int> dp(n);
        dp[n - 1] = prefixSum[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            dp[i] = max(dp[i + 1], prefixSum[i] - dp[i + 1]);
        }

        return dp[1];
    }
};