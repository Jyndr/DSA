class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();

        int a1 = nums[n - 3] * nums[n - 2] * nums[n - 1];
        int a3 = nums[0] * nums[n - 2] * nums[n - 1];
        int a4 = nums[0] * nums[1] * nums[n - 1];

        return max({a1 , a3 , a4});
    }
};