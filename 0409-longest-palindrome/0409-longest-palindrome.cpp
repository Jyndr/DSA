class Solution {
public:
    int longestPalindrome(string s) {
        

        // create hashMap

        unordered_map<char, int> mpp;
        //"abccccdd"

        for (char ch : s) {
            mpp[ch]++;
        }

       

        // a: 1, b: 1, c: 4, d: 2
        bool selectFreqOne = false;
        int count = 0;
        for (char ch: s) {
            
            // pick freq is one
            if (!selectFreqOne && mpp[ch] == 1) {
                count += 1;
                selectFreqOne = true;
                mpp[ch] = 0;
            }
            // pick freq is even
            if (mpp[ch] != 0 && mpp[ch] % 2 == 0) {
                count += mpp[ch];
                mpp[ch] = 0;
                
            }

            // pick freq is odd
            if (mpp[ch] != 1 && mpp[ch] % 2 != 0) {
                // we have to add even freq and make count 1
                int evenFreq = mpp[ch] - 1;
                count += evenFreq;
                // we have to make count 1

                mpp[ch] = 1;
            }
        }

        return count;
    }
};