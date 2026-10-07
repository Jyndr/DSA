class Solution {
public:
    set<string> ans;
    void f(int index, int cnt, string& curr, string& s, int mini) {
        if (index == s.size()) {
            if (cnt == 0) {
                ans.insert(curr);
            }
            return;
        }

        if (cnt < 0) {
            return;
        }

        int temp = cnt;
        if (s[index] == '(') {
            temp++;
        } else if (s[index] == ')') {
            temp--;
        }

        // not taking this ele
        if (mini > 0 && (s[index] == '(' || s[index] == ')')) {
            f(index + 1, cnt, curr, s, mini - 1);
        }

        curr += s[index];
        f(index + 1, temp, curr, s, mini);
        curr.pop_back();

        return;
    }
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();

        int cnt = 0;
        int mini_cnt = 0;
        for (auto it : s) {
            if (it == '(') {
                cnt++;
            } else if(it == ')') {
                cnt--;
            }
            if (cnt < 0) {
                mini_cnt++;
                cnt = 0;
            }
        }
        mini_cnt += cnt;

        string curr = "";
        f(0, 0, curr, s, mini_cnt);

        vector<string> a(ans.begin(), ans.end());
        return a;
    }
};