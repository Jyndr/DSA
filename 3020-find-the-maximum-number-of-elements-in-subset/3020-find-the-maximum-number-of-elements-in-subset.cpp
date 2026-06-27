class Solution {
public:
    int edge_case(unordered_map<int, int>& mpp) {
        // edge case handling for one
        int len_for_one = 0;
        while (true) {
            if (mpp[1] >= 2) {
                len_for_one+=2;
                mpp[1] -= 2;
            } else if (mpp[1] == 1) {
                len_for_one++;
                break;
            } else {
                len_for_one--;
                break;
            }
        }
        return len_for_one;
    }

    int maximumLength(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int, int> mpp;
        unordered_set<int> stt;

        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }

        int maxi = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (stt.find(nums[i]) == stt.end() &&
                nums[i] > 1) {           // not yet processed
                long long ans = nums[i]; // series
                int len = 0;             // its length
                while (true) {
                    if (mpp[ans] >= 2) { // move forward
                        len += 2;
                        if (ans * ans <= 1e9) {
                            ans = ans * ans;
                        } else {
                            // going out so stop
                            len--;
                            break;
                        }
                    } else if (mpp[ans] == 1) {
                        len += 1;
                        break;
                    } else {
                        len--;
                        break;
                    }
                }
                maxi = max(maxi, len);
                stt.insert(nums[i]);
            }
        }

        return max(maxi, edge_case(mpp));
    }
};