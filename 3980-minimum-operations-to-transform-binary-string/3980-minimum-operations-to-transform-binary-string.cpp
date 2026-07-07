class Solution {
public:
    int minOperations(string s1, string s2) {
        int i = 0, j = 0;
        int n = s1.size();
        int op = 0;

        while (i < n) {
            if (s1[i] == s2[j]) {
                i++;
                j++;
                continue;
            }
            if (s1[i] == '0' && s2[i] == '1') {
                op++;
                i++;
                j++;
            } else if (s1[i] == '1' && s2[i] == '0') {
                int len = 0;
                while (i < n && s1[i] == '1' && s2[j] == '0') {
                    i++;
                    j++;
                    len++;
                }

                if (len % 2 == 0) {
                    op += len / 2;
                } else if (len % 2 == 1 && len != 1) {
                    op += (len - 1) / 2 + 2;
                } else if (n > 1 && len == 1) {
                    op += 2;
                }else{
                    return -1;
                }
            } else {
                i++;
                j++;
            }
        }

        return op;
    }
};