class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end());

        long long ans = 0;

        int j = ceil((double)n / 2);

        int i = n - 1;
        while (j > 0) {
            ans += (1LL * nums[i] * nums[i]);
            i--;
            j--;
        }

        while (i >= 0) {
            ans -= (1LL * nums[i] * nums[i]);
            i--;
        }

        return ans;
    }
};