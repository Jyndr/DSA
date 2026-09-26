class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mpp;
        for (int i = 0; i < knowledge.size(); i++) {
            mpp[knowledge[i][0]] = knowledge[i][1];
        }

        int i = 0;
        string res = "";
        while (i < s.size()) {
            if (s[i] == '(') {
                int j = i + 1;
                string key = "";
                while (j < s.size() && s[j] != ')') {
                    key += s[j];
                    j++;
                }
                if (mpp.find(key) != mpp.end()) {
                    res.append(mpp[key].begin(), mpp[key].end());
                } else {
                    res += '?';
                }
                i = j + 1;
            } else {
                res += s[i];
                i++;
            }
        }

        return res;
    }
};