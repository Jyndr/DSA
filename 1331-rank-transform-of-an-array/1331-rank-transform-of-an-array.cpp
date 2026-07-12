class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> stt;
        for (int i = 0; i < arr.size(); i++) {
            stt.insert(arr[i]);
        }

        vector<int> sttt(stt.begin(), stt.end());

        vector<int> ans;
        for (int i = 0; i < arr.size(); i++) {
            int it = lower_bound(sttt.begin(), sttt.end(), arr[i]) - sttt.begin();
            ans.push_back(it + 1);
        }

        return ans;
    }
};