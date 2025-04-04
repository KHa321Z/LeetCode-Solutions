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
    pair<TreeNode*, int> recursion(TreeNode* parent) {

        if (!parent)
            return { nullptr, 0 };

        auto left = recursion(parent->left);
        auto right = recursion(parent->right);

        if (left.second > right.second)
            return { left.first, left.second + 1 };

        if (left.second < right.second)
            return { right.first, right.second + 1 };

        return { parent, left.second + 1 };

    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return recursion(root).first;
    }
};