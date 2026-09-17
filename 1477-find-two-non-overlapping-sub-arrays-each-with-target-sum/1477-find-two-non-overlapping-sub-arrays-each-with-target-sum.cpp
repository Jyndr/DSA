class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        // thought-> find all the valid subarrays's with sliding window
        int i = 0, j = 0, sum = 0, n = arr.size();
        vector<vector<int>> v;

        while (j < n) {
            sum += arr[j];
            while (sum > target) {
                sum -= arr[i];
                i++;
            }
            if (sum == target) {
                v.push_back({i, j});
            }
            j++;
        }

        sort(v.begin(), v.end());

        vector<int> suffix(v.size(), INT_MAX);
        int sizee = INT_MAX;
        for (int i = v.size() - 1; i >= 0; i--) {
            sizee = min(sizee, v[i][1] - v[i][0] + 1);
            suffix[i] = sizee;
        }

        
        int ans = INT_MAX;
        for (int i = 0; i < v.size(); i++) {
            // binary search for the other non_overlapping interval
            int valid_idx = v.size();
            int low = 0, high = v.size() - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (v[mid][0] > v[i][1]) {
                    valid_idx = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            if (valid_idx < v.size()) {
                ans = min(ans, v[i][1] - v[i][0] + 1 + suffix[valid_idx]);
            }
        }

        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};