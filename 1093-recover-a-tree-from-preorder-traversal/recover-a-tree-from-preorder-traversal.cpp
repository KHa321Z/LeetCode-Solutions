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
    int getDepth(const string& str, int& index) {
        int dep = 0;

        for (; index < str.length() && str[index] == '-'; index++)
            dep++;

        return dep;
    }

    int numberExtraction(const string& str, int& index) {
        int num = 0;

        for (; index < str.length() && str[index] != '-'; index++)
            num = 10 * num + str[index] - '0';

        return num;
    }

    int prerecover(TreeNode* parent, const string& traversal, int& index, int depth) {

        if (index == traversal.length())
            return -1;

        int dep = getDepth(traversal, index);

        if (depth + 1 != dep)
            return dep;

        parent->left = new TreeNode(numberExtraction(traversal, index));
        dep = prerecover(parent->left, traversal, index, depth + 1);

        if (dep == -1)
            return -1;

        if (depth + 1 != dep)
            return dep;

        parent->right = new TreeNode(numberExtraction(traversal, index));
        return prerecover(parent->right, traversal, index, depth + 1);

    }

    TreeNode* recoverFromPreorder(string traversal) {
        int index = 0;
        TreeNode* root = new TreeNode(numberExtraction(traversal, index));

        prerecover(root, traversal, index, 0);
        return root;
    }
};