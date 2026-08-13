class segTree {
public:
    vector<vector<int>> segT;

    segTree(int n) { segT.resize(4 * n, vector<int>(6)); }

    void updating_a_node(int node, int ch) {
        segT[node][0] = ch; // leftmost char
        segT[node][1] = 1;  // prefix len
        segT[node][2] = ch; // rightmost char
        segT[node][3] = 1;  // suffix len
        segT[node][4] = 1;  // longest len
        segT[node][5] = 1;  // size of segment
    }

    void updating_a_segment(int node) {
        int left_char_of_left_node = segT[node * 2 + 1][0];
        int left_char_of_right_node = segT[node * 2 + 2][0];
        int right_char_of_left_node = segT[node * 2 + 1][2];
        int right_char_of_right_node = segT[node * 2 + 2][2];
        int prefix_len_of_left_node = segT[node * 2 + 1][1];
        int prefix_len_of_right_node = segT[node * 2 + 2][1];
        int suffix_len_of_left_node = segT[node * 2 + 1][3];
        int suffix_len_of_right_node = segT[node * 2 + 2][3];
        int max_len_of_left_node = segT[node * 2 + 1][4];
        int max_len_of_right_node = segT[node * 2 + 2][4];
        int seg_size_of_left_node = segT[node * 2 + 1][5];
        int seg_size_of_right_node = segT[node * 2 + 2][5];

        int maxi_len = 0;
        if (left_char_of_right_node == right_char_of_left_node) {
            maxi_len = suffix_len_of_left_node + prefix_len_of_right_node;
        }

        if (prefix_len_of_left_node > maxi_len) {
            maxi_len = prefix_len_of_left_node;
        }

        if (suffix_len_of_right_node > maxi_len) {
            maxi_len = suffix_len_of_right_node;
        }

        if (max_len_of_left_node > maxi_len) {
            maxi_len = max_len_of_left_node;
        }

        if (max_len_of_right_node > maxi_len) {
            maxi_len = max_len_of_right_node;
        }

        if (prefix_len_of_left_node == seg_size_of_left_node) {
            if (left_char_of_left_node == left_char_of_right_node) {
                segT[node][1] =
                    prefix_len_of_left_node + prefix_len_of_right_node;
            } else {
                segT[node][1] = prefix_len_of_left_node;
            }
        } else {
            segT[node][1] = prefix_len_of_left_node;
        }
        segT[node][0] = left_char_of_left_node;

        if (suffix_len_of_right_node == seg_size_of_right_node) {
            if (right_char_of_right_node == right_char_of_left_node) {
                segT[node][3] =
                    suffix_len_of_left_node + suffix_len_of_right_node;
            } else {
                segT[node][3] = suffix_len_of_right_node;
            }
        } else {
            segT[node][3] = suffix_len_of_right_node;
        }
        segT[node][2] = right_char_of_right_node;

        segT[node][4] = max({maxi_len, segT[node][1], segT[node][3]});
        segT[node][5] = seg_size_of_left_node + seg_size_of_right_node;
    }

    void update(int node, int left, int right, int index, int ch) {
        if (left == right) {
            updating_a_node(node, ch);
            return;
        }
        int mid = left + (right - left) / 2;

        if (index <= mid) {
            update(node * 2 + 1, left, mid, index, ch);
        } else {
            update(node * 2 + 2, mid + 1, right, index, ch);
        }
        updating_a_segment(node);
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {

        int n = s.size();
        segTree tree(n);

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            tree.update(0, 0, n - 1, i, s[i] - 'a');
        }

        for (int i = 0; i < queryIndices.size(); i++) {
            tree.update(0, 0, n - 1, queryIndices[i], queryCharacters[i] - 'a');
            ans.push_back(tree.segT[0][4]);
        }

        return ans;
    }
};