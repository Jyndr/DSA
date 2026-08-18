class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        unordered_map<int, int> mpp;
        int n = nums.size();
        int a = nums[0];
        int b = nums[n - 1];

        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }

        if (k == 1) {
            for (int i = 50; i >= 0; i--) {
                if (mpp[i] == 1) {
                    return i;
                }
            }
            return -1;
        }

        if (k == n) {
            for (int i = 50; i >= 0; i--) {
                if (mpp[i] >= 1) {
                    return i;
                }
            }
            return -1;
        }

        if (a > b && mpp[a] == 1) {
            return a;
        } else if (mpp[b] == 1) {
            return b;
        }

        if (b > a && mpp[b] == 1) {
            return b;
        } else if (mpp[a] == 1) {
            return a;
        }

        return -1;
    }
};