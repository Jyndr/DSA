class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        unordered_set<int> stt;
        for (int i = 0; i < digits.size(); i++) {
            for (int j = 0; j < digits.size(); j++) {
                for (int k = 0; k < digits.size(); k++) {
                    if (i != j && j != k && i != k && digits[i] != 0) {
                        int num = digits[i];
                        num = num * 10 + digits[j];
                        num = num * 10 + digits[k];
                        if (num % 2 == 0) {
                            stt.insert(num);
                        }
                    }
                }
            }
        }
        return stt.size();
    }
};