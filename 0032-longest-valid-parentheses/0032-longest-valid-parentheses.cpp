class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stt;
        stt.push(-1);
        int ans = 0;
        int n = s.size();

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stt.push(i);
            } else if (s[i] == ')') {
                stt.pop();
            } if (stt.empty()) {
                stt.push(i);
            }else {
                ans = max(ans , i - stt.top());
            }
        }
        return ans;
    }
};