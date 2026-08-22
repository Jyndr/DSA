class Solution {
public:
    bool checkDivisibility(int n) {

        int pr = 1, sum = 0;
        int num = n;

        while (n > 0) {
            int dig = n % 10;
            pr *= dig;
            sum += dig;
            n /= 10;
        }

        return num % (sum + pr) == 0;
    }
};