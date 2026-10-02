class Solution {
public:
    bool check(string& s) {
        int cnt = 0;
        for (auto it : s) {
            if (it == '(') {
                cnt++;
            } else {
                cnt--;
            }
            if (cnt < 0) {
                return false;
            }
        }
        return cnt == 0;
    }

    vector<string> ans;
    void f(int index, string& s, int n) {
        if (index == n) {
            if (check(s)) {
                ans.push_back(s);
            }
            return;
        }
        s.push_back('(');
        f(index + 1, s, n);
        s.pop_back();
        s.push_back(')');
        f(index + 1, s, n);
        s.pop_back();
        return;
    }

    vector<string> generateParenthesis(int n) {
        string s = "(";
        f(1, s, n * 2);
        return ans;
    }
};