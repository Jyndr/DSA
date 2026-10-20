class Solution {
public:
    int maxii(vector<int>& nums, int i, int j) {
        int maxi = INT_MIN;
        for (int k = i; k <= j; k++) {
            maxi = max(maxi, nums[k]);
        }
        return maxi;
    }

    bool check(vector<int>& nums, int i, int j, int prev_max) {
        int pv = 0;
        int mini = INT_MAX;

        for (int k = i; k <= j; k++) {
            if (k < j) {
                if (nums[k] > nums[k + 1]) {
                    pv++;
                }
            } else {
                if (nums[k] > nums[i]) {
                    pv++;
                }
            }
            mini = min(mini, nums[k]);
        }

        return pv <= 1 && mini >= prev_max;
    }

    bool real(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int prev_max = INT_MIN;

        while (i < n) {
            if (!check(nums, i, i + k - 1, prev_max)) {
                return false;
            }
            prev_max = maxii(nums, i, i + k - 1);
            i += k;
        }
        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        
        int sum = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (real(nums, i)) {
                    sum += i;
                }
                if (n / i != i) {
                    if (real(nums, n / i)) {
                        sum += n / i;
                    }
                }
            }
        }
        return sum;
    }
};