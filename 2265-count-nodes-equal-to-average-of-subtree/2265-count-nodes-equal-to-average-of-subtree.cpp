/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    pair<int, int> f(TreeNode* node) { // returns {sum , number of nodes}
        int sum = node->val;
        int nodes = 1;
        if (node->left) {
            pair<int, int> p = f(node->left);
            sum += p.first;
            nodes += p.second;
        }
        if (node->right) {
            pair<int, int> p = f(node->right);
            sum += p.first;
            nodes += p.second;
        }
        ans += (node->val == (sum / nodes));
        return {sum , nodes};
    }
    int averageOfSubtree(TreeNode* root) {
        pair<int, int> p = f(root);
        return ans;
    }
};