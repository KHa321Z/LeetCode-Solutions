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
    int maxLevelSum(TreeNode* root) {

        int m = 1, c = 1;
        int s = root->val, t = 0;
        queue<pair<TreeNode *, int>> q;

        q.push({ root, c });

        while (!q.empty()) {

            auto [n, l] = q.front();
            q.pop();

            if (n->right)
                q.push({ n->right, l + 1 });
            
            if (n->left)
                q.push({ n->left, l + 1 });

            if (l == c)
                t += n->val;
            
            else if (t > s)
                s = t, m = c, c = l, t = n->val;
            
            else
                c = l, t = n->val;

        }

        if (t > s)
            m = c;

        return m;
        
    }
};