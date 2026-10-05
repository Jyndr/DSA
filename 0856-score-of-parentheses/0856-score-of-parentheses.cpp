class Solution {
public:
    int f(int i, int j, string& s) {
        if (j < i) { // no string now
            return 1;
        }

        int score = 0, k = i;
        while (k <= j) {
            int st = k, closing = k;
            int temp = 0;
            while (st <= j) {
                if (s[st] == '(') {
                    temp++;
                } else {
                    temp--;
                }
                if (temp == 0) { // we found the closing bracket
                    closing = st;
                    break;
                }
                st++;
            }
            if (closing - k + 1 <= 2) {
                score += f(k + 1, closing - 1, s);
            } else {
                score += 2 * f(k + 1, closing - 1, s);
            }
            k = closing + 1;
        }
        return score;
    }
    int scoreOfParentheses(string s) { return f(0, s.size() - 1, s); }
};