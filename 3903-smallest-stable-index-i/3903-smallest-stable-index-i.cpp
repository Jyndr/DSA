class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> mini(n, INT_MAX);
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1) {
                mini[i] = min(nums[i], mini[i + 1]);
            } else {
                mini[i] = nums[i];
            }
        }

        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            if (maxi - mini[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};