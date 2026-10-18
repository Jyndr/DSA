class Solution {
public:
    // Calculate the sum of digits recursively
    int sumofdigits(int n) {
        if (!n) return 0;
        return n % 10 + sumofdigits(n / 10);
    }

    int minSwaps(vector<int>& nums1) {
        // Create a copy to get the required sorted order
        vector<int> nums2 = nums1;

        // Sort by digit sum, then by numeric value
        sort(nums2.begin(), nums2.end(), [this](int a, int b) {
            int x = sumofdigits(a);
            int y = sumofdigits(b);

            if (x == y) return a < b;
            return x < y;
        });

        // Store each number's target index
        unordered_map<int, int> mp;
        for (int i = 0; i < nums2.size(); i++) {
            mp[nums2[i]] = i;
        }

        int ans = 0;
        int i = 0;

        // Place each number at its correct index
        while (i < nums1.size()) {
            if (mp[nums1[i]] == i) {
                // Number is already at its target index
                i++;
            } else {
                // Swap the number with the element at its target index
                ans++;
                swap(nums1[mp[nums1[i]]], nums1[i]);
            }
        }

        return ans;
    }
};