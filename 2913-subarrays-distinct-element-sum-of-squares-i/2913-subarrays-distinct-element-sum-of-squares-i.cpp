class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            set<int> stt;
            for (int j = i; j < nums.size(); j++) {
                stt.insert(nums[j]);
                ans += (stt.size() * stt.size());
            }
        }

        return ans;
    }
};