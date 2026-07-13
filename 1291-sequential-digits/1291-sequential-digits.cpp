class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> arr = {
            12,     123,   1234,  12345, 123456, 1234567, 12345678, 123456789,
            23,     234,   2345,  23456, 234567, 2345678, 23456789, 3456789,
            345678, 34567, 3456,  345,   34,     456789,  45678,    4567,
            456,    45,    56789, 5678,  567,    56,      6789,     678,
            67,     789,   78,    89};

        sort(arr.begin(), arr.end());

        int st = lower_bound(arr.begin(), arr.end(), low) - arr.begin();
        int end = lower_bound(arr.begin(), arr.end(), high + 1) - arr.begin();

        vector<int> ans;
        for (int i = st; i < end; i++) {
            ans.push_back(arr[i]);
        }

        return ans;
    }
};