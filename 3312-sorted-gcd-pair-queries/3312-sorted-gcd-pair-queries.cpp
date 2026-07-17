class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxV = *max_element(nums.begin(), nums.end());

        vector<int> cnt(maxV + 1, 0);
        for (int x : nums) cnt[x]++;

        // freq[v] = count of elements divisible by v
        vector<long long> freq(maxV + 1, 0);
        for (int v = 1; v <= maxV; v++)
            for (int k = v; k <= maxV; k += v)
                freq[v] += cnt[k];

        // exact[v] = count of pairs whose gcd is exactly v
        vector<long long> exact(maxV + 1, 0);
        for (int v = maxV; v >= 1; v--) {
            long long pairs = freq[v] * (freq[v] - 1) / 2; // gcd is a multiple of v
            for (int k = 2 * v; k <= maxV; k += v)
                pairs -= exact[k];
            exact[v] = pairs;
        }

        vector<long long> prefix(maxV + 1, 0);
        for (int v = 1; v <= maxV; v++)
            prefix[v] = prefix[v - 1] + exact[v];

        vector<int> ans;
        ans.reserve(queries.size());
        for (long long q : queries) {
            long long target = q + 1; // smallest v with prefix[v] >= target
            int lo = 1, hi = maxV, res = maxV;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (prefix[mid] >= target) { res = mid; hi = mid - 1; }
                else lo = mid + 1;
            }
            ans.push_back(res);
        }
        return ans;
    }
};