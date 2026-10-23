class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) {
                ans &= i;
            }
        }

        if (ans == INT_MAX) {
            return 0;
        }
        return ans;
    }
};