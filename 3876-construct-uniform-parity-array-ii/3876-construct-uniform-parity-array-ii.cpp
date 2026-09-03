class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool all_odd = true, all_even = true;
        int min_ele = INT_MAX;

        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] % 2 == 0) {
                all_odd = false;
            } else {
                all_even = false;
            }
            min_ele = min(min_ele, nums1[i]);
        }
        if (all_odd || all_even || min_ele % 2 == 1) {
            return true;
        }
        return false;
    }
};