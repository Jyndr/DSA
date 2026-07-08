#define ll long long
class Solution {
public:
    const int mod = 1e9 + 7;

    ll binary_expo(ll a, ll b) {
        ll ans = 1;
        while (b > 0) {
            if (b % 2 == 0) {
                a = (a * a) % mod;
                b /= 2;
            } else {
                ans = (ans * a) % mod;
                b--;
            }
        }
        return ans;
    }

    ll add(ll a, ll b) { return (a + b) % mod; }
    ll sub(ll a, ll b) { return (a - b + mod) % mod; }
    ll mul(ll a, ll b) { return ((a % mod) * (b % mod)) % mod; }
    ll div(ll a, ll b) { return (mul(a, binary_expo(b, mod - 2))); }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<ll> num(n, 0), power(n, 0), prefix_sum(n, 0);

        ll number = 0;
        ll pow = 0;

        for (int i = n - 1; i >= 0; i--) {
            ll dig = (ll)(s[i] - '0');

            if (dig > 0) {
                ll ten = binary_expo(10LL, pow);
                ll whole_new = mul(dig, ten);
                number = add(whole_new, number);
                pow++;
            }

            if (i < n - 1) {
                prefix_sum[i] = add(prefix_sum[i], prefix_sum[i + 1]);
            }
            prefix_sum[i] = add(prefix_sum[i], dig);

            power[i] = pow;
            num[i] = number;
        }

        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int left = queries[i][0];
            int right = queries[i][1];

            ll pref = 0, pow = 0, nn = 0;
            if (right + 1 < n) {
                pref = prefix_sum[right + 1];
                pow = power[right + 1];
                nn = num[right + 1];
            }

            ll power_of_ten = binary_expo(10LL, pow);
            ll real_ans = div(sub(num[left], nn), power_of_ten);

            ll final_a = mul(real_ans, sub(prefix_sum[left], pref));
            ans[i] = (int)final_a;
        }

        return ans;
    }
};