class Solution {
public:
    long long dp[16][2][2][2];
    long long f(int index, int carry, bool lz1, bool lz2, string& s) {

        if (index == -1) {
            return carry == 0;
        }

        if (dp[index][carry][lz1][lz2] != -1) {
            return dp[index][carry][lz1][lz2];
        }

        long long ans = 0;

        for (int dig1 = 0; dig1 <= 9; dig1++) {
            if (dig1 == 0 && index == s.size() - 1) {
                continue;
            }
            if (lz1 && dig1 != 0) {
                continue;
            }
            for (int dig2 = 0; dig2 <= 9; dig2++) {
                if (lz2 && dig2 != 0) {
                    continue;
                }
                if (dig2 == 0 && index == s.size() - 1) {
                    continue;
                }

                int sum = (dig1 + dig2 + carry) % 10;
                int fc = (dig1 + dig2 + carry) / 10;

                if (sum == s[index] - '0') {
                    ans += f(index - 1, fc, dig1 == 0, dig2 == 0, s);
                }
            }
        }

        return dp[index][carry][lz1][lz2] = ans;
    }
    long long countNoZeroPairs(long long n) {

        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return f(s.size() - 1, 0, false, false, s);
    }
};