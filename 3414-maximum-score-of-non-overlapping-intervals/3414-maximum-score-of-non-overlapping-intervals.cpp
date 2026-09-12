class Node {
public:
    long long score;
    vector<int> idx;
    Node() { score = 0; }
};

Node dp[50001][5];
int vis[50001][5];
class Solution {
public:
    Node f(int i, int k, vector<vector<int>>& intervals) {
        if (k <= 0 || i >= intervals.size()) {
            return *(new Node());
        }

        if (vis[i][k] != 0) {
            return dp[i][k];
        }

        Node res = f(i + 1, k, intervals);

        // if taking
        int new_index = intervals[i][4]; // by binary_search
        int sc = intervals[i][2];        // weight of that one
        Node temp = f(new_index, k - 1, intervals);
        temp.score += sc;
        temp.idx.push_back(
            intervals[i][3]); // pushing the current interval real index

        sort(temp.idx.begin(), temp.idx.end());

        if (temp.score > res.score) {
            res = temp;
        } else if (temp.score == res.score) {
            if (temp.idx < res.idx) {
                res = temp;
            }
        }
        vis[i][k] = 1;
        return dp[i][k] = res;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        for (int i = 0; i <= intervals.size(); i++) { // reseting the dp
            for (int j = 0; j <= 4; j++) {
                vis[i][j] = 0;
            }
        }

        for (int i = 0; i < intervals.size(); i++) {
            intervals[i].push_back(i);
        }

        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < intervals.size(); i++) {
            int curr_end = intervals[i][1];

            int low = 0, high = intervals.size() - 1;
            int ans_indx = intervals.size();
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (intervals[mid][0] > curr_end) {
                    ans_indx = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            intervals[i].push_back(ans_indx);
        }

        Node t = f(0, 4, intervals);
        return t.idx;
    }
};