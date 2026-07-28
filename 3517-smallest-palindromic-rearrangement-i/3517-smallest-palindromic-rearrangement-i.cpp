class Solution {
public:
    string smallestPalindrome(string s) {
        string first = "";
        int n = s.size();
        vector<int> freq(26);
        string ans = "";

        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }

        // first putting odd length
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                freq[i]--;
                ans.push_back(i + 'a');
            }
        }

        for (int i = 25; i >= 0; i--) {
            if (freq[i] % 2 == 0) {
                while (freq[i] > 0) {
                    freq[i] -= 2;
                    first.push_back(i + 'a');
                    ans.push_back(i + 'a');
                }
            }
        }

        reverse(first.begin(), first.end());

        return first + ans;
    }
};