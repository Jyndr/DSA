#define ll long long
class Solution {
public:
    ll dp[5001];
    bool should_be_do_operation(string& source, string& target, int ind,
                                int till) {
        if (ind + till > source.size()) {
            return false;
        }

        int end = ind + till - 1;
        while (ind <= end) {
            if (source[ind] != target[ind]) {
                return true;
            }
            ind++;
        }

        return false;
    }

    bool valid_for_operation(string& source, string& target, string& a,
                             string& b, int ind) {

        int j = 0;
        while (j < b.size() && ind < source.size()) {
            if (source[ind] == a[j] && b[j] == target[ind]) {
                ind++;
                j++;
            } else if (a[j] == '*' && b[j] == target[ind]) {
                j++;
                ind++;
            } else {
                return false;
            }
        }
        return true;
    }

    ll f(int index, vector<vector<string>>& rules, vector<int>& costs,
         string& source, string& target) {
        if (index >= source.size()) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }
        ll ans = INT_MAX;
        bool did_op = false;

        for (int i = 0; i < rules.size(); i++) {
            if (should_be_do_operation(source, target, index,
                                       rules[i][0].size())) {
                if (valid_for_operation(source, target, rules[i][0],
                                        rules[i][1], index)) {
                    ans = min(ans,
                              costs[i] * 1LL + f(index + rules[i][0].size(),
                                                 rules, costs, source, target));
                    did_op = true;
                }
            }
        }

        if (source[index] == target[index]) {
            ans = min(ans, f(index + 1, rules, costs, source, target));
        }
        return dp[index] = ans;
    }

    int minCost(string source, string target, vector<vector<string>>& rules,
                vector<int>& costs) {

        for (int i = 0; i < rules.size(); i++) {
            for (int j = 0; j < rules[i][0].size(); j++) {
                costs[i] += (rules[i][0][j] == '*');
            }
        }

        memset(dp, -1, sizeof(dp));

        ll ans = f(0, rules, costs, source, target);

        if (ans >= INT_MAX) {
            return -1;
        }
        return ans;
    }
};