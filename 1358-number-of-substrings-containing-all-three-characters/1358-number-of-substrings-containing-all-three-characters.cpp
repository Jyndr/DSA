class Solution {
public:
    bool check(unordered_map<char, int>& mpp) {
        return mpp['a'] > 0 && mpp['b'] > 0 && mpp['c'] > 0;
    }

    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        int i = 0, j = 0;
        unordered_map<char, int> mpp;

        while (j < n) {
            mpp[s[j]]++;

            while (check(mpp)) {
                mpp[s[i]]--;
                i++;
            }
            ans += i;
            j++;
        }

        return ans;
    }
};