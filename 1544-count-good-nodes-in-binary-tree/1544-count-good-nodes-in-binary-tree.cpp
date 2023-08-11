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
    int goodNodes(TreeNode* root) {
        int n = 0;

        goodNodesHelper(root, n, root -> val);
        return n;
    }

    int goodNodesHelper(TreeNode* root, int &n, int prev_max) {
        if (root == nullptr) {
            return 0;
        }

        if (root -> val >= prev_max) {
            prev_max = root -> val;
            n += 1;
        }
        
        goodNodesHelper(root -> left, n, prev_max);
        goodNodesHelper(root -> right, n, prev_max);
        return 0;
    }
};