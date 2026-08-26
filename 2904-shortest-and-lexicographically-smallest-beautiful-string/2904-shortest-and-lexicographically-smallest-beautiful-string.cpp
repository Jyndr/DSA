class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int i = 0, j = 0, n = s.size();
        string a = "";
        while (a.size() < n) {
            a += '1';
        }
        int ans = INT_MAX;
        int cnt1 = 0, cnt0 = 0;

        while (j < n) {
            if (s[j] == '1')
                cnt1++;
            else
                cnt0++;

            while (cnt1 > k) {
                if (s[i] == '1')
                    cnt1--;
                else
                    cnt0--;
                i++;
            }
            while (i < j && s[i] == '0') {
                cnt0--;
                i++;
            }
            if (cnt1 == k) {
                ans = min(ans, j - i + 1);
            }
            j++;
        }

        if (ans == INT_MAX) { // edge case
            return "";
        }

        i = 0;
        while (i + ans <= n) {
            cnt1 = 0;
            for (int k = i; k < i + ans; k++) {
                cnt1 += (s[k] == '1');
            }
            if (cnt1 == k) {
                if (s.substr(i, ans) < a) {
                    a = s.substr(i, ans);
                }
            }
            i++;
        }

        return a;
    }
};