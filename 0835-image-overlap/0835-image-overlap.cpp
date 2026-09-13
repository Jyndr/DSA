class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        // row offset can go from 1 - n to n - 1 and col also for each
        int maxi = 0;
        for (int r = 1 - n; r <= n - 1; r++) {
            for (int c = 1 - n; c <= n - 1; c++) {
                int cnt = 0;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        int image2 = img2[i][j];
                        int image1 = 0;
                        if (i + r < n && i + r >= 0 && j + c < n &&
                            j + c >= 0) {
                            image1 = img1[i + r][j + c];
                        }
                        if (image1 == 1 && image1 == image2) {
                            cnt++;
                        }
                    }
                }
                maxi = max(maxi, cnt);
            }
        }
        return maxi;
    }
};