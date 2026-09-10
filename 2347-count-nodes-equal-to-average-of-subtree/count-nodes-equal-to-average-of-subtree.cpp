/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // {nodes, sum}
    pair<int, int> calc(TreeNode* node, int& cnt) {
        if (!node)
            return { 0, 0 };
        
        auto l = calc(node->left, cnt);
        auto r = calc(node->right, cnt);
        pair<int, int> c = { l.first + r.first + 1, l.second + r.second + node->val };

        if (c.second / c.first == node->val)
            cnt++;
            
        return c;
    }

    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;
        calc(root, cnt);
        return cnt;
    }
};