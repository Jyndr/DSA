#define ll long long
const int mod = 1e9 + 7;
class Solution {
public:
    ll dp[201][201][201];
    ll f(int index, int gcd1, int gcd2, vector<int>& nums) {
        if (index == nums.size()) {
            return gcd1 > 0 && gcd2 > 0 && gcd1 == gcd2;
        }

        if (dp[index][gcd1][gcd2] != -1) {
            return dp[index][gcd1][gcd2];
        }

        ll ans = 0;

        // choosing s1
        ans = (ans + f(index + 1, gcd(gcd1, nums[index]), gcd2, nums)) % mod;

        // choosing s2
        ans = (ans + f(index + 1, gcd1, gcd(gcd2, nums[index]), nums)) % mod;

        // choosing none
        ans = (ans + f(index + 1, gcd1, gcd2, nums)) % mod;

        // creating new sequences
        // if (gcd1 == 0 && gcd2 == 0) {
        //     ans = (ans + f(index + 1, nums[index], 0, nums)) % mod;
        //     ans = (ans + f(index + 1, 0, nums[index], nums)) % mod;
        // }

        return dp[index][gcd1][gcd2] = ans;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return f(0, 0, 0, nums);
    }
};