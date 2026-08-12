class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        int i = 0, j = 0, longest = 0;
        unordered_map<int, int> mpp;
        while (j < nums.size()) {
            mpp[nums[j]]++;

            while (i < j && mpp[nums[j]] > k) {
                mpp[nums[i]]--;
                i++;
            }

            longest = max(longest, j - i + 1);
            j++;
        }

        return longest;
    }
};