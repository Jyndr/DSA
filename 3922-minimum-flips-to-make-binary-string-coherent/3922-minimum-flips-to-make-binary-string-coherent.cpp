class Solution {
public:
    int minFlips(string s) {
        int n = s.size();

        int cnt1 = 0;
        int cnt0 = 0;
        for (int i = 0; i < n; i++) {
            cnt1 += (s[i] == '1');
            cnt0 += (s[i] == '0');
        }

        if (cnt0 == 0 || cnt1 == 0 || n == 1) {
            return 0;
        }

        if ((s[0] == '1' && s[n - 1] == '0') ||
            (s[0] == '0' && s[n - 1] == '1')) {
            return min(cnt1 - 1, cnt0);
        } else if (s[0] == '1' && s[n - 1] == '1') {
            return min(cnt0, cnt1 - 2);
        } else {
            return min(cnt1 - 1, cnt0);
        }

        return 0;
    }
};