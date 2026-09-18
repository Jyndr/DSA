class Solution {
public:
    // Finds the index of the first segment that starts STRICTLY AFTER 'end_idx'
    int bs(int end_idx, const vector<pair<int, int>>& vec) {
        int low = 0, high = vec.size() - 1;
        int ans = vec.size();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (vec[mid].first > end_idx) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    // Compares two states: {max_substrings, min_total_length}
    pair<int, int> compare(const pair<int, int>& p1, const pair<int, int>& p2) {
        if (p1.first > p2.first) return p1;
        if (p1.first < p2.first) return p2;
        if (p1.second < p2.second) return p1;
        return p2;
    }

    // Recursive DP
    pair<int, int> f(int index, const vector<pair<int, int>>& vec, 
                     vector<pair<int, int>>& dp, vector<int>& vis, 
                     vector<int>& next_choice) {
        // Base case
        if (index >= vec.size()) {
            return {0, 0};
        }
        // Memoization check
        if (vis[index] != -1) {
            return dp[index];
        }

        pair<int, int> best_res = {0, 0};
        int best_next = -1;

        // Try picking every valid segment starting from 'index' onwards
        for (int i = index; i < vec.size(); i++) {
            // Find the next available segment using your Binary Search
            int next_idx = bs(vec[i].second, vec);
            
            // Get the best result from the remaining string
            pair<int, int> a = f(next_idx, vec, dp, vis, next_choice);
            a.first += 1;                                  // Add 1 to substring count
            a.second += (vec[i].second - vec[i].first + 1); // Add length of current segment
            
            // Compare it with our running best
            pair<int, int> better = compare(best_res, a);
            
            // If picking this segment gives us a better or equal score, save the choice!
            if (better == a) {
                best_res = a;
                best_next = i; // STATE RECONSTRUCTION: Record the index we chose
            }
        }

        vis[index] = 1;
        next_choice[index] = best_next; 
        return dp[index] = best_res;
    }

    // Helper to get fully valid substrings
    int getRightBoundary(int startIdx, const string& s, const vector<vector<int>>& v) {
        int right = v[s[startIdx] - 'a'][1];
        for (int j = startIdx; j <= right; j++) {
            if (v[s[j] - 'a'][0] < startIdx) return -1; // Aborts if it overlaps incorrectly
            right = max(right, v[s[j] - 'a'][1]);
        }
        return right;
    }

    vector<string> maxNumOfSubstrings(string s) {
        vector<vector<int>> v(26, vector<int>(2, -1));
        int n = s.size();

        // 1. Get first and last occurrences
        for (int i = 0; i < n; i++) {
            if (v[s[i] - 'a'][0] == -1) {
                v[s[i] - 'a'][0] = i;
            }
            v[s[i] - 'a'][1] = i;
        }

        // 2. Extract valid segments using boundary validation
        vector<pair<int, int>> vec;
        for (int i = 0; i < 26; i++) {
            if (v[i][0] != -1) {
                int left = v[i][0];
                int right = getRightBoundary(left, s, v);
                if (right != -1) {
                    vec.push_back({left, right});
                }
            }
        }

        // 3. SORT is mandatory for the binary search to work!
        sort(vec.begin(), vec.end());

        int m = vec.size(); // At most 26!
        vector<pair<int, int>> dp(m);
        vector<int> vis(m, -1);
        vector<int> next_choice(m, -1); // Array to remember the path

        // 4. Fill DP table
        f(0, vec, dp, vis, next_choice);

        // 5. STATE RECONSTRUCTION (The magic happens here)
        vector<string> ans;
        int curr = 0;
        
        while (curr < m) {
            int chosen_seg = next_choice[curr]; // What segment did the DP choose at this state?
            if (chosen_seg == -1) break;        // If nothing was chosen, we are done.
            
            // Reconstruct the actual string and push it to answer
            int len = vec[chosen_seg].second - vec[chosen_seg].first + 1;
            ans.push_back(s.substr(vec[chosen_seg].first, len));
            
            // Jump to the next valid state using your BS function
            curr = bs(vec[chosen_seg].second, vec); 
        }

        return ans;
    }
};