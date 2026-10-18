class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<pair<int, int>> v1, v2;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            int num = nums[i];
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            v1.push_back({sum, nums[i]});
            v2.push_back({sum, nums[i]});
        }

        sort(v2.begin(), v2.end());

        map<pair<int, int>, int> mpp;
        for (int i = 0; i < v2.size(); i++) {
            mpp[v2[i]] = i;
        }

        int swaps = 0;
        int i = 0;
        while(i < nums.size()) {
            int curr = i;
            int to_go = mpp[v1[i]];
            if (curr != to_go) {
                swaps++;
                swap(v1[curr], v1[to_go]);
            } else {
                i++;
            }
        }

        return swaps;
    }
};