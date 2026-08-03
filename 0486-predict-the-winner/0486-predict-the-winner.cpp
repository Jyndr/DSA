class Solution {
public:
    int dp[21][21][2];
    int f(int i, int j, int parity, vector<int>& nums) {
        if (j < i) {
            return 0;
        }

        if (dp[i][j][parity] != INT_MIN) {
            return dp[i][j][parity];
        }

        if (parity) {
            return dp[i][j][parity] = max(nums[i] + f(i + 1, j, 0, nums),
                                          nums[j] + f(i, j - 1, 0, nums));
        } else {
            return dp[i][j][parity] = min(f(i + 1, j, 1, nums) - nums[i],
                                          f(i, j - 1, 1, nums) - nums[j]);
        }
        return 0;
    }
    bool predictTheWinner(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                for (int k = 0; k < 2; k++) {
                    dp[i][j][k] = INT_MIN;
                }
            }
        }
        return f(0, nums.size() - 1, 1, nums) >= 0;
    }
};