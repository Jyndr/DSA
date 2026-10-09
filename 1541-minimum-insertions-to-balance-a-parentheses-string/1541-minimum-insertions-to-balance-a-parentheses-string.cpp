class Solution {
public:
    int minInsertions(string s) {

        int score = 0, n = s.size(), i = 0;
        stack<char> stt;

        while (i < n) {
            if (s[i] == '(') {
                stt.push(s[i]);
                i++;
            } else {
                if (i + 1 < n && s[i] == s[i + 1]) {
                    if (stt.size() > 0) { // there is a opening for them
                        stt.pop();
                    } else {
                        score++;
                    }
                    i += 2;
                } else {
                    if (stt.size() > 0) {
                        stt.pop();
                        score++;
                    } else {
                        score += 2;
                    }
                    i++;
                }
            }
        }
        score += stt.size() * 2;

        return score;
    }
};