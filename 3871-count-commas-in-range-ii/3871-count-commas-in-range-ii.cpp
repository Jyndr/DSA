class Solution {
public:
    // 3 dig - 0
    // 4 dig - 1
    // 5 dig - 1
    // 6 dig - 1
    // 7 dig - 2
    // 8 dig - 2
    // 9 dig - 2
    // 10 dig - 3
    long long countCommas(long long n) {
        long long ans = 0;
        while (n > 0) {
            long long num = n;
            int dig = 0;
            while (num > 0) { // counting number of digits in n
                dig++;
                num /= 10;
            }
            int score = 0;
            if (dig % 3 == 0) {
                score = dig / 3 - 1;
            } else {
                score = dig / 3;
            }
            long long new_n = 0;
            while (dig > 1) { // creating 999...
                new_n = new_n * 10 + 9;
                dig--;
            }
            ans = ans + (score * (n - new_n));
            n = new_n;
        }
        return ans;
    }
};