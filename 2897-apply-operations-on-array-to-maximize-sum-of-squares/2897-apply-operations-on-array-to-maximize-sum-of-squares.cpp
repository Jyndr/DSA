class Solution {
public:
    const int mod = 1e9 + 7;
    int maxSum(vector<int>& nums, int k) {
        vector<int> freq(32, 0);

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < 32; j++) {
                if (nums[i] & (1 << j)) {
                    freq[j]++;
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < k; i++) {
            long long curr = 0;
            for (int j = 31; j >= 0; j--) {
                if (freq[j] > 0) {
                    curr |= (1LL << j);
                    freq[j]--;
                }
            }
            ans = (ans + (curr * curr) % mod) % mod;
        }

        return ans;
    }
};