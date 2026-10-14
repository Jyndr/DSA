class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";

        for (int i = 0; i < num; i++) {
            int dig = min(9, sum);
            ans += (dig + '0');
            sum -= dig;
        }

        if (sum != 0) {
            return "";
        } else {
            return ans;
        }
    }
};