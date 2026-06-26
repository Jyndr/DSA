class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();
        unordered_map<int, int> mpp;

        int cumsum = 0;
        long long ans = 0;
        long long valid_points = 0;
        mpp[0] = 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                valid_points += mpp[cumsum];
                cumsum++;
            } else {
                cumsum--;
                valid_points -= mpp[cumsum];
            }
            ans += valid_points;
            mpp[cumsum]++;
        }
        return ans;
    }
};