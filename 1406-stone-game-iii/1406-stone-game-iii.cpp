class Solution {
public:
    int dp[50001][4][2];
    int f(int index, int moves_left, int parity, vector<int>& stoneValue) {
        if (index == stoneValue.size()) {
            return 0;
        }

        if (dp[index][moves_left][parity] != INT_MIN) {
            return dp[index][moves_left][parity];
        }

        if (parity) { // alice chance
            int ans = INT_MIN;

            // using moves
            if (moves_left) {
                if (moves_left == 1) {
                    ans = max(ans, stoneValue[index] +
                                       f(index + 1, 3, 0, stoneValue));
                } else {
                    ans = max(ans,
                              stoneValue[index] +
                                  f(index + 1, moves_left - 1, 1, stoneValue));
                }
            }

            // not using
            if (moves_left < 3)
                ans = max(ans, f(index, 3, 0, stoneValue));
            return dp[index][moves_left][parity] = ans;

        } else {
            int ans = INT_MAX;

            // using moves
            if (moves_left) {
                if (moves_left == 1) {
                    ans = min(ans, f(index + 1, 3, 1, stoneValue) -
                                       stoneValue[index]);
                } else {
                    ans = min(ans, f(index + 1, moves_left - 1, 0, stoneValue) -
                                       stoneValue[index]);
                }
            }

            // not using
            if (moves_left < 3)
                ans = min(ans, f(index, 3, 1, stoneValue));

            return dp[index][moves_left][parity] = ans;
        }
        return 0;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        for (int i = 0; i < stoneValue.size(); i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 2; k++) {
                    dp[i][j][k] = INT_MIN;
                }
            }
        }

        int ans = f(0, 3, 1, stoneValue);

        if (ans > 0) {
            return "Alice";
        } else if (ans == 0) {
            return "Tie";
        } else
            return "Bob";
    }
};