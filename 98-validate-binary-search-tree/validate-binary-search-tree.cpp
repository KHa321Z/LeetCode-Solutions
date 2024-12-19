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
    bool isValidNode(TreeNode* parent, long minrange, long maxrange) {

        if (!parent)
            return true;

        return ((minrange < parent->val && parent->val < maxrange) && isValidNode(parent->left, minrange, parent->val) && isValidNode(parent->right, parent->val, maxrange));

    }

    bool isValidBST(TreeNode* root) {

        if (!root)
            return true;
        
        return ((!root->left || isValidNode(root->left, LONG_MIN, root->val)) && (!root->right || isValidNode(root->right, root->val, LONG_MAX)));

    }
};