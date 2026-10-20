class Solution {
public:
    bool poss(int div, vector<int>& nums) {
        int i = 0, n = nums.size(), prev_largest = INT_MIN;

        while (i < n) {
            int pivot = 0, smallest = INT_MAX, largest = INT_MIN, j = i;
            while (j < i + div) {
                int desired_idx = i + ((j + 1) % div);
                pivot += (nums[j] > nums[desired_idx]);
                smallest = min(smallest, nums[j]);
                largest = max(largest, nums[j]);
                j++;
            }
            if (pivot > 1 || smallest < prev_largest) {
                return false;
            }
            prev_largest = largest;
            i = j;
        }

        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size(), sum = 0;

        if (n == 1) {
            return 1;
        }

        // div = 1;
        bool sorted = true;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                sorted = false;
            }
        }
        if (sorted) {
            sum += 1;
        }

        // div = n;
        if (poss(n, nums)) {
            sum += n;
        }

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                if (poss(i, nums)) {
                    sum += i;
                }
                if (n / i != i) {
                    if (poss(n / i, nums)) {
                        sum += n / i;
                    }
                }
            }
        }

        return sum;
    }
};