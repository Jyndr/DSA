class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) {
            return n;
        }

        long long num = 2;
        while (num * 2 <= n) {
            num = num * 2;
        }

        return num * 2;
    }
};