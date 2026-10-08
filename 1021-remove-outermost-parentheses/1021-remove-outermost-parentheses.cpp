class Solution {
public:
    string removeOuterParentheses(string s) {

        int n = s.size();
        vector<int> will_be_removed(n);

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                will_be_removed[i] = 1;
            }
            if (s[i] == '(') {
                cnt++;
            } else
                cnt--;

            if (cnt == 0) {
                will_be_removed[i] = 1;
            }
        }

        string ans = "";

        for (int i = 0; i < n; i++) {
            if (will_be_removed[i] == 1) {
                continue;
            }
            ans += s[i];
        }

        return ans;
    }
};