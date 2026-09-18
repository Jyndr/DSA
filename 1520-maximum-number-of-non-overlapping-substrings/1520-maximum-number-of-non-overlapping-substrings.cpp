class Solution {
public:
    int bs(int index, vector<pair<int, int>>& vec) {
        int low = 0, high = vec.size() - 1;
        int ans = vec.size();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // FIX: Changed from '>' to '>=' so it doesn't skip segments starting exactly at 'index'
            if (vec[mid].first >= index) { 
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    pair<int, int> compare(pair<int, int>& p1, pair<int, int>& p2) {
        if (p1.first > p2.first) {
            return p1;
        } else if (p1.first < p2.first) {
            return p2;
        } else {
            if (p1.second < p2.second) {
                return p1;
            } else
                return p2;
        }
        return {0, 0};
    }

    pair<int, int> f(int index, vector<pair<int, int>>& vec, int n,
                     vector<pair<int, int>>& dp, vector<int>& vis, vector<int>& next_choice) {
        if (index >= n) {
            return {0, 0};
        }

        // FIX: Changed vis[i] to vis[index] based on your parameter
        if (vis[index] != -1) {
            return dp[index];
        }

        pair<int, int> p = {0, 0};
        int best_next = -1; // Added for state reconstruction

        int st_idx = bs(index, vec);

        for (int i = st_idx; i < vec.size(); i++) {
            // FIX: Passed dp, vis, and next_choice arrays, and changed vec[i][1] to vec[i].second
            pair<int, int> a = f(vec[i].second + 1, vec, n, dp, vis, next_choice);
            a.first += 1;
            a.second += (vec[i].second - vec[i].first + 1);
            
            pair<int, int> better = compare(p, a);
            if (better == a) { // If 'a' won the comparison, save this choice
                p = a;
                best_next = i;
            }
        }

        vis[index] = 1;
        next_choice[index] = best_next; // Store the choice made at this string index
        return dp[index] = p;
    }

    vector<string> maxNumOfSubstrings(string s) {
        vector<vector<int>> v(26, vector<int>(2, -1));
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (v[s[i] - 'a'][0] == -1) {
                v[s[i] - 'a'][0] = i;
            }
            v[s[i] - 'a'][1] = i;
        }

        vector<pair<int, int>> vec;
        for (int i = 0; i < v.size(); i++) {
            if (v[i][0] != -1) {
                // INLINE EXPANSION: Replaced your basic push_back with an inline while-loop 
                // to expand the boundaries safely without needing an external helper function.
                int left = v[i][0];
                int right = v[i][1];
                bool valid = true;
                
                for (int j = left; j <= right; j++) {
                    if (v[s[j] - 'a'][0] < left) {
                        valid = false;
                        break;
                    }
                    right = max(right, v[s[j] - 'a'][1]);
                }
                
                if (valid) {
                    vec.push_back({left, right});
                }
            }
        }
        
        // SORT is still mandatory here so your Binary Search works
        sort(vec.begin(), vec.end());

        // now i have all the starting and ending occurence of each char
        vector<pair<int, int>> dp(n);
        vector<int> vis(n, -1);
        vector<int> next_choice(n, -1); // Added this array
        
        pair<int, int> p = f(0, vec, n, dp, vis, next_choice);

        // FINAL RECONSTRUCTION LOOP
        vector<string> ans;
        int curr = 0;
        while (curr < n && next_choice[curr] != -1) {
            int chosen = next_choice[curr];
            int start = vec[chosen].first;
            int length = vec[chosen].second - vec[chosen].first + 1;
            
            ans.push_back(s.substr(start, length));
            curr = vec[chosen].second + 1; // Jump index exactly as your DP did
        }
        
        return ans;
    }
};