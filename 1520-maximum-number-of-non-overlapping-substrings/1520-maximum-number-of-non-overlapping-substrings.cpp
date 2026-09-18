class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> st(26, -1);
        vector<int> end(26, -1);
        vector<bool> isvalid(26, true);

        for (int i = 0; i < n; i++) {
            if (st[s[i] - 'a'] == -1) {
                st[s[i] - 'a'] = i;
            }
            end[s[i] - 'a'] = i;
        }

        for (int c = 0; c < 26; c++) {
            if (st[c] == -1) {
                continue;
            }
            for (int i = st[c]; i <= end[c]; i++) {
                if (st[s[i] - 'a'] < st[c]) {
                    isvalid[c] = false;
                    break;
                }
                end[c] = max(end[c], end[s[i] - 'a']);
            }
        }

        vector<string> result;
        int last_st = INT_MAX;

        for (int i = n - 1; i >= 0; i--) {
            if (isvalid[s[i] - 'a'] && st[s[i] - 'a'] == i &&
                end[s[i] - 'a'] < last_st) {
                last_st = i;
                result.push_back(s.substr(i, end[s[i] - 'a'] - i + 1));
            }
        }

        return result;
    }
};