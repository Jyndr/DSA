class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        vector<int> freq(26);

        bool sorted = true;
        char largest = 'a', smallest = 'z';
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && s[i] > s[i + 1]) {
                sorted = false;
            }
            freq[s[i] - 'a']++;
            if (s[i] > largest) {
                largest = s[i];
            }
            if (s[i] < smallest) {
                smallest = s[i];
            }
        }

        if (sorted) {
            return 0;
        } else if (!sorted && n == 2) {
            return -1;
        } else if (s[0] == smallest || s[n - 1] == largest) {
            return 1;
        } else if (s[0] == largest && freq[largest - 'a'] == 1 &&
                   s[n - 1] == smallest && freq[smallest - 'a'] == 1) {
            return 3;
        }
        return 2;
    }
};