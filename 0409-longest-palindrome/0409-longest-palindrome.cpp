class Solution {
public:
    int longestPalindrome(string s) {
        int cnt = 0;

        unordered_map<char, int> mpp;

        for (int i = 0; i < s.size(); i++) {
            mpp[s[i]]++;
        }

        bool one_odd = false;

        for (auto it : mpp) {
            if (it.second % 2 == 1 && !one_odd) {
                cnt += it.second;
                one_odd = !one_odd;
            } else if (it.second % 2 == 1) {
                cnt += it.second - 1;
            } else {
                cnt += it.second;
            }
        }

        return cnt;
    }
};