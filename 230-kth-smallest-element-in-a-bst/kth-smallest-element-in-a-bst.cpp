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
    int inorder(TreeNode* node, int& k) {

        if (!node)
            return INT_MIN;

        int left = inorder(node->left, k);

        cout << "HEre";

        if (!--k)
            return node->val;
            
        else if (left != INT_MIN)
            return left;

        return inorder(node->right, k);

    }

public:
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }
};