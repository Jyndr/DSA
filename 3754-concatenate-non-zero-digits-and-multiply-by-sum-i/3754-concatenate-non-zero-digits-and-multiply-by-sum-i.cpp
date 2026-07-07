class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long sum = 0;

        while (n > 0) {
            if (n % 10 != 0) {
                x = x * 10 + n % 10;
            }
            sum += n % 10;
            n /= 10;
        }

        long long new_x = 0;
        while (x > 0) {
            new_x = new_x * 10 + x % 10;
            x /= 10;
        }

        return new_x * sum;
    }
};