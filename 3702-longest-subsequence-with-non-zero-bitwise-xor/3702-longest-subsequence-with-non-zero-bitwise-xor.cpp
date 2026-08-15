class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        bool non_zero = false;
        int xorr = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                non_zero = true;
            }
            xorr ^= nums[i];
        }

        if (xorr != 0) {
            return n;
        } else if (non_zero) {
            return n - 1;
        } else
            return 0;
    }
};