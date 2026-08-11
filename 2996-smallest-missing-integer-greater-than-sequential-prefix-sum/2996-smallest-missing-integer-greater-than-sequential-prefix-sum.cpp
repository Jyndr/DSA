class Solution {
public:
    int missingInteger(vector<int>& nums) {

        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else
                break;
        }

        unordered_set<int>stt;

        for (int i = 0; i < nums.size(); i++) {
            stt.insert(nums[i]);
        }

        while (stt.find(sum) != stt.end()) {
            sum++;
        }

        return sum;
    }
};