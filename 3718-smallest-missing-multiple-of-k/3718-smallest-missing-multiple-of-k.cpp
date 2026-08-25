class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> stt;

        for (int i = 0; i < nums.size(); i++) {
            stt.insert(nums[i]);
        }

        int multiple = 1;
        while (stt.find(k * multiple) != stt.end()) {
            multiple++;
        }

        return k * multiple;
    }
};