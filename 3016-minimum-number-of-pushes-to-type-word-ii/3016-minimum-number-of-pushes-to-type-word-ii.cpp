class Solution {
public:
    int minimumPushes(string word) {

        vector<int> v(26);

        for (int i = 0; i < word.size(); i++) {
            v[word[i] - 'a']++;
        }

        vector<int> sorted;
        for (int i = 0; i < 26; i++) {
            if (v[i]) {
                sorted.push_back(v[i]);
            }
        }

        sort(sorted.rbegin() , sorted.rend());

        int ans = 0;

        for(int i = 0;i<sorted.size();i++){
            ans += sorted[i] * (i / 8 + 1);
        }

        return ans;
    }
};