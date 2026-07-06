class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& i) {

        for (int j = 0; j < i.size(); j++) {
            i[j][1] *= -1;
        }

        sort(i.begin(), i.end());

        int low = 0, high = 0;
        int cnt = 0;

        for (int j = 0; j < i.size(); j++) {
            i[j][1] *= -1;
            if (i[j][1] <= high && i[j][0] >= low) {
                continue;
            }
            high = i[j][1];
            low = i[j][0];
            cnt++;
        }

        return cnt;
    }
};