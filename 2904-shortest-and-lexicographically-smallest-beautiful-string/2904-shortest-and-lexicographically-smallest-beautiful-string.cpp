class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int i = 0, j = 0, n = s.size();
        int cnt1 = 0, cnt0 = 0, ans = INT_MAX;

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

        string a = "";
        while (a.size() < ans) {
            a += '1';
        }

        i = 0;
        while (i + ans <= n) {
            cnt1 = 0;
            for (int l = i; l < i + ans; l++) {
                cnt1 += (s[l] == '1');
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