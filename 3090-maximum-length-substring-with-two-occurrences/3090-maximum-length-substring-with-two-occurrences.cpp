class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i = 0, j = 0 , ans = 0;
        unordered_map<char, int> mpp;

        while (j < s.size()) {
            mpp[s[j]]++;
            while (i < j && mpp[s[j]] > 2) {
                mpp[s[i]]--;
                i++;
            }
            ans = max(ans , j - i + 1);
            j++;
        }

        return ans;
    }
};