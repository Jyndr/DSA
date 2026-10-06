class Solution {
public:
    int minAddToMakeValid(string s) {
        int op = 0, cnt = 0;

        for (auto it : s) {
            if (it == '(') {
                cnt++;
            } else {
                cnt--;
            }
            if (cnt < 0) {
                op++;
                cnt = 0;
            }
        }
        if (cnt > 0) {
            op += cnt;
        }

        return op;
    }
};