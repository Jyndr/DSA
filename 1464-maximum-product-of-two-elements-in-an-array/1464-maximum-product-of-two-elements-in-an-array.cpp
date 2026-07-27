class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxi = INT_MIN;
        int second_maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxi) {
                second_maxi = maxi;
                maxi = nums[i];
            } else if (nums[i] > second_maxi) {
                second_maxi = nums[i];
            }
        }

        return (maxi - 1) * (second_maxi - 1);
    }
};