class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {

        long long m = 1e5, k = k1 + k2, n = nums1.size();
        vector<int> v(m + 1);

        for (int i = 0; i < n; i++) {
            v[abs(nums1[i] - nums2[i])]++;
        }

        long long ans = 0;

        for (int i = m; i > 0; i--) {
            long long freq = v[i];
            long long op = min(k, freq);
            v[i - 1] += op;
            v[i] -= op;
            k -= op;
            if (v[i] > 0) {
                ans += (1LL * i * i * v[i]);
            }
        }

        return ans;
    }
};