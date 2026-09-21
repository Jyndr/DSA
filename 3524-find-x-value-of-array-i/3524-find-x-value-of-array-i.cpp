class Solution {
public:
    long long dp[100001][6][2][2];
    long long f(int i, long long prod, bool taking, bool took, int k, int x,
                vector<int>& nums) {
        if (i == nums.size()) {
            return (took || taking) && prod == x;
        }

        if (dp[i][prod][taking][took] != -1) {
            return dp[i][prod][taking][took];
        }

        long long ans = 0;

        // not taking
        if (taking == true) {
            ans += f(i + 1, prod, false, true, k, x, nums);
        } else {
            ans += f(i + 1, prod, false, took, k, x, nums);
        }

        // taking
        if (!took) {
            ans += f(i + 1, (nums[i] * prod) % k, true, false, k, x, nums);
        }
        return dp[i][prod][taking][took] = ans;
    }
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans;

        for (int i = 0; i < k; i++) {
            memset(dp, -1, sizeof(dp));
            ans.push_back(f(0, 1LL, 0, 0, k, i, nums));
        }

        return ans;
    }
};