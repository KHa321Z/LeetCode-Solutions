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
    int s(TreeNode* root) {

        if (!root)
            return 0;

        return root->val + s(root->left) + s(root->right);

    }

    int p(TreeNode* root, int s, long long& m) {

        if (!root)
            return 0;

        int l = p(root->left, s, m);
        int r = p(root->right, s, m);
        int left = abs(s - l);
        int right = abs(s - r);

        if (abs(l - s + l) < abs(m - s + m))
            m = l;
        
        if (abs(r - s + r) < abs(m - s + m))
            m = r;

        return l + r + root->val;

    }

    int maxProduct(TreeNode* root) {

        const int MOD = 1e9 + 7;
        long long m = INT_MAX;
        int su = s(root);

        p(root, su, m);

        return (m) % MOD * (su - m) % MOD;
        
    }
};