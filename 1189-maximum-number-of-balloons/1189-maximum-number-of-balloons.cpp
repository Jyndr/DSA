class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string target = "balloon";
        unordered_map<char, int> mpp;

        for (int i = 0; i < text.size(); i++) {
            mpp[text[i]]++;
        }

        int cnt = 0;
        int pt = 0;

        while (true) {
            if (mpp[target[pt]] > 0) {
                mpp[target[pt]]--;
                pt++;
                if (pt == target.size()) {
                    pt = 0;
                    cnt++;
                }
            } else {
                break;
            }
        }

        return cnt;
    }
};