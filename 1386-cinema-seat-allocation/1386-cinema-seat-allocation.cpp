class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        vector<vector<int>> arr = {{2, 3, 4, 5}, {4, 5, 6, 7}, {6, 7, 8, 9}};

        int id = 1, ans = 0;
        unordered_map<int, int> row_to_id;

        sort(reservedSeats.begin(), reservedSeats.end());

        int prev_row = 0;
        for (int i = 0; i < reservedSeats.size(); i++) {
            int row = reservedSeats[i][0];
            if (row_to_id[row] == 0) {
                int not_existing_rows = row - prev_row - 1;
                ans += 2 * not_existing_rows; // one row can have atmost 2 grps

                row_to_id[row] = id;
                id++;
                prev_row = row;
            }
        }

        ans += 2 * (n - prev_row);

        // now we have cnt distinct rows;
        vector<vector<int>> rs(id, vector<int>(11, 0));

        for (int i = 0; i < reservedSeats.size(); i++) {
            int row = reservedSeats[i][0];
            int id = row_to_id[row];
            int col = reservedSeats[i][1];
            rs[id][col] = 1;
        }

        for (int i = 0; i < 3; i++) {
            for (int row = 1; row < id; row++) {
                bool poss = true;
                for (int col = arr[i][0]; col <= arr[i][3]; col++) {
                    if (rs[row][col]) {
                        poss = false;
                        break;
                    }
                }

                if (poss) {
                    for (int col = arr[i][0]; col <= arr[i][3]; col++) {
                        rs[row][col] = 1;
                    }
                    ans++;
                }
            }
        }

        return ans;
    }
};