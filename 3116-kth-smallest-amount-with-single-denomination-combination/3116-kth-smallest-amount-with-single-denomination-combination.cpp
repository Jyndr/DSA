#define ll long long
class Solution {
public:
    ll countSmaller(vector<int>& coins, ll mid) {
        int n = coins.size();
        ll ans = 0;

        for (ll exp = 1; exp <= (1 << n) - 1; exp++) {
            ll lcm = 0;
            ll parity = 0;

            for (ll i = 0; i < n; i++) {
                if (exp & (1LL << i)) {
                    parity++;
                    if (lcm == 0) {
                        lcm = coins[i];
                    } else {
                        lcm = ((coins[i] * lcm) / gcd(coins[i], lcm));
                    }
                }
            }

            if (parity % 2 == 0) {
                ans -= (mid / lcm);
            } else {
                ans += (mid / lcm);
            }
        }
        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        ll low = 1;
        ll high = (ll)*max_element(begin(coins), end(coins)) * k;

        ll a = -1;

        while (low <= high) {
            ll mid = low + (high - low) / 2;

            ll ans = countSmaller(coins, mid);
            if (ans >= k) {
                a = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return a;
    }
};