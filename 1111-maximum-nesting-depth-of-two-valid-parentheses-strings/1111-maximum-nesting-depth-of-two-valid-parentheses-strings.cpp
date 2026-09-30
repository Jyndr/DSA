class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int cnt0 = 0, cnt1 = 0;
        vector<int> res;

        for (int i = 0; i < seq.size(); i++) {
            if (seq[i] == '(') { // choose min of both
                if (cnt0 < cnt1) {
                    res.push_back(0);
                    cnt0++;
                } else {
                    res.push_back(1);
                    cnt1++;
                }
            } else { // choose max of both
                if (cnt0 > cnt1) {
                    res.push_back(0);
                    cnt0--;
                } else {
                    res.push_back(1);
                    cnt1--;
                }
            }
        }

        return res;
    }
};