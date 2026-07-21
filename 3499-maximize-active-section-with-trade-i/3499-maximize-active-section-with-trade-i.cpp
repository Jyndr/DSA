class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        vector<int> next_one(n, -1), last_one(n, -1), prev_cnt(n), next_cnt(n);

        int temp = -1;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            last_one[i] = temp;
            prev_cnt[i] = cnt;
            if (s[i] == '1') {
                temp = i;
                cnt++;
            }
        }

        temp = n;
        cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            next_one[i] = temp;
            next_cnt[i] = cnt;
            if (s[i] == '1') {
                temp = i;
                cnt++;
            }
        }

        int ans = 0, i = 0;
        while (i < n) {
            if (s[i] == '1') {
                int j = i;
                while (j < n && s[j] == '1') {
                    j++;
                }
                j--;
                if (next_one[j] > j + 1 && last_one[i] < i - 1) {
                    int a = prev_cnt[i] + next_cnt[j];
                    ans = max(ans, next_one[j] - last_one[i] + a - 1);
                }
                i = j + 1;
            } else {
                i++;
            }
        }
        return max(cnt, ans);
    }
};