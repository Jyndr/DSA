class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_map<string, int> stt;

        for (int i = 0; i < patterns.size(); i++) {
            stt[patterns[i]]++;
        }

        int cnt = 0;

        for (int i = 0; i < word.size(); i++) {
            string s = "";
            for (int j = i; j < word.size(); j++) {
                s += word[j];
                cnt += stt[s];
                stt[s] = 0;
            }
        }
        return cnt;
    }
};