class Solution {
public:
    int dp[101][101];
    bool f(int index, int cnt, string& s) {
        if (cnt < 0) {
            return false;
        }

        if (index == s.size()) {
            return cnt == 0;
        }

        if (dp[index][cnt] != -1) {
            return dp[index][cnt];
        }

        bool ans = false;

        if (s[index] == '(') {
            ans = f(index + 1, cnt + 1, s);
        } else if (s[index] == ')') {
            ans = f(index + 1, cnt - 1, s);
        } else {
            ans = f(index + 1, cnt - 1, s) || f(index + 1, cnt + 1, s) ||
                  f(index + 1, cnt, s);
        }

        return dp[index][cnt] = ans;
    }

    bool checkValidString(string s) {
        memset(dp, -1, sizeof(dp));
        return f(0, 0, s);
    }
};