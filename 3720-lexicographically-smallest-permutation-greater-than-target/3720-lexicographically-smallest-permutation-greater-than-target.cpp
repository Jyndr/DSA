class Solution {
public:
    string ans = "";
    bool f(string& curr, string& target, int i, vector<int>& cnt,
           bool Already_Greater) {
        if (i == target.size()) {
            if (Already_Greater) {
                ans = curr;
                return true;
            }
            return false;
        }

        for (char c = 'a'; c <= 'z'; c++) {
            if (cnt[c - 'a'] == 0)
                continue;

            if (!Already_Greater && c < target[i])
                continue;

            curr += c;
            cnt[c - 'a']--;

            bool Now_greater = Already_Greater || c > target[i];

            if (f(curr, target, i + 1, cnt, Now_greater)) {
                return true;
            }

            curr.pop_back();
            cnt[c - 'a']++;
        }

        return false;
    }

    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26, 0);
        for (int i = 0; i < s.size(); i++) {
            cnt[s[i] - 'a']++;
        }

        string curr = "";

        bool a = f(curr, target, 0, cnt, false);

        return ans;
    }
};