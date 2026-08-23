class Solution {
public:
    bool sumGame(string num) {

        int sum1 = 0, sum2 = 0, cnt1 = 0, cnt2 = 0, n = num.size();

        for (int i = 0; i < n / 2; i++) {
            if (num[i] != '?') {
                sum1 += num[i] - '0';
            } else {
                cnt1++;
            }
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] != '?') {
                sum2 += num[i] - '0';
            } else {
                cnt2++;
            }
        }

        bool alice = true;
        while (cnt1 > 0 || cnt2 > 0) {
            if (sum1 < sum2) {
                swap(sum1, sum2);
                swap(cnt1, cnt2);
            } // assuming first part for the max part

            int diff = sum1 - sum2;

            if (alice) {
                if (cnt1 > 0) { // if max part is avl make the diff more great
                    sum1 += 9;
                    cnt1--;
                } else {
                    if (diff < 9) {
                        sum2 += 9;
                    }else{
                        sum2 += 0;
                    }
                    cnt2--;
                }
            } else {
                if (cnt2 > 0) { // same
                    if (diff <= 9) {
                        sum2 += diff;
                    } else {
                        sum2 += 9;
                    }
                    cnt2--;
                } else {
                    cnt1--;
                }
            }
            alice = !alice;
        }

        return sum1 != sum2;
    }
};