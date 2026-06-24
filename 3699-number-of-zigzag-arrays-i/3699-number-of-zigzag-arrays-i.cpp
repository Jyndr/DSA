#define ll long long
const int mod = 1e9 + 7;
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<vector<ll>> prev_vec(m + 1, vector<ll>(2, 0));
        vector<vector<ll>> curr_vec(m + 1, vector<ll>(2, 0));

        // base case
        for (int prev = 1; prev <= m; prev++) {
            prev_vec[prev][1] = 1;
            prev_vec[prev][0] = 1;
        }

        for (int i = n - 1; i >= 1; i--) {

            vector<ll> cumsum0(m + 1);
            vector<ll> cumsum1(m + 1);

            for (int val = 1; val <= m; val++) {
                cumsum0[val] = (cumsum0[val - 1] + prev_vec[val][0]) % mod;
                cumsum1[val] = (cumsum1[val - 1] + prev_vec[val][1]) % mod;
            }

            for (int prev = 1; prev <= m; prev++) {
                curr_vec[prev][0] = cumsum1[prev - 1];
                curr_vec[prev][1] = (cumsum0[m] - cumsum0[prev] + mod) % mod;
            }
            prev_vec = curr_vec;
        }

        ll ans = 0;
        for (int prev = 1; prev <= m; prev++) {
            ans = (ans + prev_vec[prev][0] + prev_vec[prev][1]) % mod;
        }

        return ans;
    }
};