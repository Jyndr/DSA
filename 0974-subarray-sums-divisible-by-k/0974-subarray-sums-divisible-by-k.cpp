class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int ans = 0;
        long long pref_sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            pref_sum += nums[i];
            int a = pref_sum % k;
            if (a < 0) {
                a = k + a;
            }
            ans += mpp[a];
            mpp[a]++;
        }
        return ans;
    }
};