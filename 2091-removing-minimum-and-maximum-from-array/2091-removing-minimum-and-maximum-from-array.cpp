class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int smallest_idx = 0, largest_idx = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[largest_idx]) {
                largest_idx = i;
            }

            if (nums[i] < nums[smallest_idx]) {
                smallest_idx = i;
            }
        }

        if (smallest_idx > largest_idx) {
            swap(smallest_idx, largest_idx);
        }

        return min({largest_idx + 1, n - smallest_idx,
                   smallest_idx + 1 + n - largest_idx});
    }
};