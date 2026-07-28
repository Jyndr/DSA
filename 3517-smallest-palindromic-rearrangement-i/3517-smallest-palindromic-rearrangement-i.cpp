class Solution {
public:
    string smallestPalindrome(string s) {
        deque<char> dq;
        int n = s.size();
        vector<int> freq(26);

        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }

        // first putting odd length
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                freq[i]--;
                dq.push_back(i + 'a');
            }
        }

        for (int i = 25; i >= 0; i--) {
            if (freq[i] % 2 == 0) {
                while (freq[i] > 0) {
                    freq[i] -= 2;
                    dq.push_back(i + 'a');
                    dq.push_front(i + 'a');
                }
            }
        }

        string ans = "";
        while (!dq.empty()) {
            ans += dq.front();
            dq.pop_front();
        }

        return ans;
    }
};