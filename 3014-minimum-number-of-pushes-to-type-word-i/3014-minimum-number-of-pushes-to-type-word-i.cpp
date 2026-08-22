class Solution {
public:
    int minimumPushes(string word) {

        int cnt = 2, ans = 0, a = 1;

        for (int i = 0; i < word.size(); i++) {
            ans += a;
            cnt++;

            if (cnt == 10) {
                cnt = 2;
                a++;
            }
        }

        return ans;
    }
};