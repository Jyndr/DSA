class Solution {
public:
    bool isValid(string s) {
        stack<char> stt;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stt.push(s[i]);
            } else {
                if (!stt.empty()) {
                    if ((s[i] == ')' && stt.top() == '(') ||
                        (s[i] == '}' && stt.top() == '{') ||
                        (s[i] == ']' && stt.top() == '[')) {
                        stt.pop();
                    } else {
                        return false;
                    }
                }else return false;
            }
        }
        return stt.size() == 0;
    }
};