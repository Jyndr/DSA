class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool all_odd = true, all_even = true;
        int min_even = INT_MAX;

        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] % 2 == 0) {
                all_odd = false;
                min_even = min(min_even, nums1[i]);
            } else {
                all_even = false;
            }
        }
        if (all_odd || all_even) {
            return true;
        }

        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] % 2 == 1 && nums1[i] < min_even) {
                return true;
            }
        }
        return false;
    }
};