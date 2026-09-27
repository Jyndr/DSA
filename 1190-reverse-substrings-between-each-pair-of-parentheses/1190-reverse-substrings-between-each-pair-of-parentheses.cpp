class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> stt;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')') {
                string temp = "";
                while (!stt.empty() && stt.top() != '(') {
                    temp.push_back(stt.top());
                    stt.pop();
                }
                stt.pop();
                for (auto it : temp) {
                    stt.push(it);
                }
            } else {
                stt.push(s[i]);
            }
        }

        string res = "";
        while (!stt.empty()) {
            res.push_back(stt.top());
            stt.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};