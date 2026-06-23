#define ll long long
class Solution {
public:
    const int mod = 1e9 + 7;
    int zigZagArrays(int n, int l, int r) {
        ll m = r - l + 1;

        if (n == 1) {
            return m;
        }

        vector<ll> up(m + 1);
        vector<ll> down(m + 1);

        for (int v = 1; v <= m; v++) {
            up[v] = v - 1;
            down[v] = m - v;
        }

        for (int i = 2; i < n; i++) {
            vector<ll> newup(m + 1);
            vector<ll> newdown(m + 1);

            ll pref = 0, suff = 0;
            for (int v = 1; v <= m; v++) {
                newup[v] = pref;
                pref = (pref + down[v]) % mod;
            }

            for (int v = m; v >= 1; v--) {
                newdown[v] = suff;
                suff = (suff + up[v]) % mod;
            }

            up = newup;
            down = newdown;
        }

        ll ans = 0;
        for (int v = 1; v <= m; v++) {
            ans = (ans + up[v] + down[v]) % mod;
        }

        return ans;
    }
};