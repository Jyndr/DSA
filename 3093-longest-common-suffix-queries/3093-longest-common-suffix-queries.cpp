class node {
public:
    node* v[26] = {nullptr};
    int smallest_idx;

    node() { smallest_idx = -1; }

    void add_next(char c, node* new_node) { v[c - 'a'] = new_node; }

    bool contains(char c) { return v[c - 'a'] != nullptr; }

    node* next(char c) { return v[c - 'a']; }

    ~node() {
        for (int i = 0; i < 26; i++) {
            if (v[i] != nullptr) {
                delete v[i];
            }
        }
    }
};

class trie {
public:
    node* root;

    trie() { root = new node(); }

    void insert(int idx, vector<string>& words) {
        node* n = root;
        for (int i = 0; i < words[idx].size(); i++) {
            char c = words[idx][i];
            if (!n->contains(c)) {
                node* new_node = new node();
                n->add_next(c, new_node);
            }
            n = n->next(c);
            if (n->smallest_idx == -1) {
                n->smallest_idx = idx;
            } else if (words[n->smallest_idx].size() > words[idx].size()) {
                n->smallest_idx = idx;
            }
        }
    }

    int check(string& word) {
        node* n = root;
        int prev = -1;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (!n->contains(c)) {
                break;
            }
            n = n->next(c);
            prev = n->smallest_idx;
        }
        return prev;
    }

    ~trie() { delete root; }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& words, vector<string>& query) {

        trie tree;

        int small = 0;
        for (int i = 0; i < words.size(); i++) {
            reverse(words[i].begin(), words[i].end());
            tree.insert(i, words);
            if (words[small].size() > words[i].size()) {
                small = i;
            }
        }

        vector<int> ans;
        for (int i = 0; i < query.size(); i++) {
            reverse(query[i].begin(), query[i].end());
            int a = tree.check(query[i]);
            if (a == -1) {
                ans.push_back(small);
            } else
                ans.push_back(a);
        }
        return ans;
    }
};