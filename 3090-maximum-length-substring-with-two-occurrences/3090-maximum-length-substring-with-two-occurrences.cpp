class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans = 0;

    for (int i = 0; i < s.size(); i++) {
        unordered_map<char,int> freq;

        for (int j = i; j < s.size(); j++) {
            freq[s[j]]++;

            if (freq[s[j]] > 2)
                break;

            ans = max(ans, j - i + 1);
        }
    }

    return ans;
        
    }
};