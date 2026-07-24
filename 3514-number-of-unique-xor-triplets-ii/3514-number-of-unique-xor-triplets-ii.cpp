class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> stt;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                stt.insert(nums[j] ^ nums[i]);
            }
        }

        unordered_set<int> new_set;
        for (auto it : stt) {
            for (int i = 0; i < nums.size(); i++) {
                new_set.insert(it ^ nums[i]);
            }
        }

        return new_set.size();
    }
};