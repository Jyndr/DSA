class Solution {
public:
    // prefix_sum + binary_search
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        vector<int> prefix_sum(n);
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                prefix_sum[i] += prefix_sum[i - 1];
            }
            prefix_sum[i] += nums[i];
        }

        if (prefix_sum[n - 1] == x) {
            return n;
        }

        int right_pt = n;
        int right_sum = 0;
        int gl = INT_MAX;

        while (right_pt > 0) {
            int low = 0, high = right_pt - 1;
            int find_sum = x - right_sum;
            int ans = -1;

            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (prefix_sum[mid] == find_sum) {
                    ans = mid;
                    break;
                } else if (prefix_sum[mid] > find_sum) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            if (ans != -1 || right_sum == x) {
                gl = min(gl, n - right_pt + ans + 1);
            }

            // updating
            right_pt--;
            right_sum += nums[right_pt];
        }

        if (gl != INT_MAX) {
            return gl;
        }

        return -1;
    }
};