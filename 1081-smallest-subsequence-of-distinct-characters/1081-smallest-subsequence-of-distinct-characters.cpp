class Solution {
public:
    string smallestSubsequence(string s) {

        string ans = "";
        vector<int> vis(26), done(26);

        for (int i = 0; i < s.size(); i++) {
            vis[s[i] - 'a'] = i;
        }

        for (int i = 0; i < s.size(); i++) {
            while (!ans.empty() && ans.back() > s[i] &&
                   vis[ans.back() - 'a'] > i && done[s[i] - 'a'] == 0) {
                done[ans.back() - 'a'] = 0;
                ans.pop_back();
            }
            if (!done[s[i] - 'a']) {
                ans.push_back(s[i]);
                done[s[i] - 'a'] = 1;
            }
        }

        return ans;
    }
};