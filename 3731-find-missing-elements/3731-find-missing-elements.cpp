class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        unordered_set<int> stt;
        int smallest = INT_MAX, largest = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            stt.insert(nums[i]);
            largest = max(largest, nums[i]);
            smallest = min(smallest, nums[i]);
        }

        vector<int> ans;

        for (int i = smallest; i <= largest; i++) {
            if (stt.find(i) == stt.end()) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};