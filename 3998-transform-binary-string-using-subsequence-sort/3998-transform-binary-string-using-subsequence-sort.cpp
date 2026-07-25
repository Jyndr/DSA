class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size();
        vector<vector<int>> freq(n, vector<int>(2, 0));

        for (int i = 0; i < n; i++) {
            if (i > 0) {
                freq[i][0] = freq[i - 1][0];
                freq[i][1] = freq[i - 1][1];
            }
            freq[i][0] += (s[i] == '0');
            freq[i][1] += (s[i] == '1');
        }

        vector<bool> ans;
        for (int i = 0; i < strs.size(); i++) {
            vector<int> zero_freq(n);
            for (int j = n - 1; j >= 0; j--) {
                if (j < n - 1) {
                    zero_freq[j] = zero_freq[j + 1];
                }
                zero_freq[j] += (strs[i][j] == '0');
            }

            int cnt0 = 0, cnt1 = 0;
            bool a = (zero_freq[0] <= freq[n - 1][0]);
            for (int j = 0; j < n; j++) {
                if (strs[i][j] == '0') {
                    cnt0++;
                } else if (strs[i][j] == '1') {
                    cnt1++;
                } else {
                    if (cnt0 + zero_freq[j] < freq[n - 1][0]) {
                        cnt0++;
                    } else {
                        cnt1++;
                    }
                }
                if (cnt1 > freq[j][1]) {
                    a = false;
                    break;
                }
            }
            ans.push_back(a);
        }
        return ans;
    }
};