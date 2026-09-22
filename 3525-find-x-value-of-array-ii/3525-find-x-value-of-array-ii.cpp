class Node {
public:
    int cnt[5] = {0};
    int prod;

    Node() { prod = 1; }
};

class SegmentTree {
public:
    vector<Node> tree;
    int n;
    int k;

    SegmentTree(int n, int k) {
        this->n = n;
        this->k = k;
        tree.resize(4 * n);
    }

    void update(int i, int val) { SegUpdate(0, 0, n - 1, val, i); }

    Node query(int st) { return SegQuery(0, 0, n - 1, st, n - 1); }

    // Node SegQuery(int node, int left, int right, int st, int end) {
    //     if (left >= st && right <= end) {
    //         return tree[node];
    //     }

    //     int mid = left + (right - left) / 2;

    //     if (st <= mid) {
    //         return SegQuery(node * 2 + 1, left, mid, st, end);
    //     }
    //     if (st > mid) {
    //         return SegQuery(node * 2 + 2, mid + 1, right, st, end);
    //     }

    //     Node l = SegQuery(node * 2 + 1, left, mid, st, end);
    //     Node r = SegQuery(node * 2 + 2, mid + 1, right, st, end);
    //     return tree[node];
    // }

    Node SegQuery(int node, int left, int right, int ql, int qr) {
        // No overlap
        if (right < ql || left > qr) {
            return Node(); // prod = 1, cnt[] = {0}
        }

        // Complete overlap
        if (ql <= left && right <= qr) {
            return tree[node];
        }

        int mid = (left + right) / 2;

        Node L = SegQuery(node * 2 + 1, left, mid, ql, qr);
        Node R = SegQuery(node * 2 + 2, mid + 1, right, ql, qr);

        return merge(L, R);
    }
    void SegUpdate(int node, int left, int right, int val, int index) {
        if (left == right) {
            updateLeaf(node, val);
            return;
        }

        int mid = left + (right - left) / 2;
        if (index <= mid) {
            SegUpdate(node * 2 + 1, left, mid, val, index);
        } else {
            SegUpdate(node * 2 + 2, mid + 1, right, val, index);
        }

        tree[node] = merge(tree[node * 2 + 1], tree[node * 2 + 2]);
        return;
    }

    void updateLeaf(int node, int val) {
        int ans = val % k;

        for (int i = 0; i < k; i++) {
            tree[node].cnt[i] = 0;
        }

        tree[node].cnt[ans] = 1;
        tree[node].prod = ans;
    }

    // Node merge(Node L, Node R) {
    //     Node res;

    //     res.prod = (L.prod * R.prod) % k;

    //     for (int i = 0; i < k; i++) {
    //         res.cnt[i] = L.cnt[i];

    //         int pr = (L.prod * i) % k;
    //         res.cnt[pr] += R.cnt[i];
    //     }

    //     return res;
    // }

    Node merge(Node L, Node R) {
        Node res;

        res.prod = (L.prod * R.prod) % k;

        // First, copy all frequencies from L
        for (int i = 0; i < k; i++) {
            res.cnt[i] = L.cnt[i];
        }

        // Then, add the shifted frequencies from R
        for (int i = 0; i < k; i++) {
            int pr = (L.prod * i) % k;
            res.cnt[pr] += R.cnt[i];
        }

        return res;
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& q) {
        int n = nums.size();
        SegmentTree tree(n, k);

        vector<int> result;

        for (int i = 0; i < n; i++) {
            tree.update(i, nums[i]);
        }

        for (auto it : q) {
            int idx = it[0];
            int val = it[1];
            int st = it[2];
            int x = it[3];

            tree.update(idx, val);
            Node ans = tree.query(st);

            result.push_back(ans.cnt[x]);
        }

        return result;
    }
};