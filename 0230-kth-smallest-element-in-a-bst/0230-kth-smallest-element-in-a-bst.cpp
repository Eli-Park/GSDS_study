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
    int kthSmallest(TreeNode* root, int k) {
        int temp = 0;
        int fin;
        inorderHelper(root, temp, k, fin);
        return fin;   
    }

    int inorderHelper(TreeNode* root, int &n, int k, int &f) {
        if (root == nullptr) {
            return 0;
        }

        inorderHelper(root -> left, n, k, f);
        //cout<<root->val<<" ";
        n += 1;
        if (n == k) {
            f = root->val;
        }
        inorderHelper(root -> right, n, k , f);
        return 0;
    }
};