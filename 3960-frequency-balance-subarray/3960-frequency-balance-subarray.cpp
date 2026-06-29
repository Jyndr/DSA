class Solution {
public:
    bool check(unordered_map<int, int>& mpp) { // constant
        if (mpp.size() == 1 || mpp.size() > 2) {
            return false;
        }

        vector<int> ans;
        for (auto it : mpp) { // O(2);
            ans.push_back(it.first);
        }
        sort(ans.begin(), ans.end()); // O(2);

        return ans[0] * 2 == ans[1];
    }

    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mpp1;
            unordered_map<int, int> mpp2;
            for (int j = i; j < n; j++) {
                if (mpp1[nums[j]] > 0) {
                    mpp2[mpp1[nums[j]]]--;
                    if (mpp2[mpp1[nums[j]]] == 0) {
                        mpp2.erase(mpp1[nums[j]]);
                    }
                }
                mpp1[nums[j]]++;
                mpp2[mpp1[nums[j]]]++;
                if (check(mpp2) || mpp1[nums[j]] == j - i + 1) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};