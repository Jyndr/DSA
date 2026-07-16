#define ll long long
class Solution {
public:
    long long gcdSum(vector<int>& nums) {

        int n = nums.size();
        vector<ll> prefix(n);

        ll maxi = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, (ll)nums[i]);
            prefix[i] = gcd(maxi, (ll)nums[i]);
        }

        sort(prefix.begin(), prefix.end());

        ll ans = 0;
        int i = 0, j = n - 1;

        while (i < j) {
            ans += gcd(prefix[i], prefix[j]);
            i++;
            j--;
        }

        return ans;
    }
};