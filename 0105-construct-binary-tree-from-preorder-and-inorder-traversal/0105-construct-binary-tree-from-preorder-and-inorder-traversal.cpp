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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        TreeNode* curNode = root;

        int cur_ind;
        int new_ind;
        int new_val;

        unordered_map<int, int> ind_map;

        for(auto ele : preorder) {
            auto iter = find(inorder.begin(), inorder.end(), ele);
            cur_ind = distance(inorder.begin(), iter);
            ind_map[ele]= cur_ind;
        }
        
        for (int i = 1; i < preorder.size(); i++) {
            new_val = preorder[i];
            new_ind = ind_map[new_val];

            while(curNode != nullptr) {
                cur_ind = ind_map[curNode->val];

                if (cur_ind < new_ind) {
                    if (curNode -> right == nullptr) {
                        TreeNode* newNode = new TreeNode(new_val);
                        curNode -> right = newNode;
                        break;
                    }
                    else {
                        curNode = curNode -> right;
                    }
                }
                else {
                    if (curNode -> left == nullptr) {
                        TreeNode* newNode = new TreeNode(new_val);
                        curNode -> left = newNode;
                        break;
                    }
                    else {
                        curNode = curNode -> left;
                    }
                }
            }

            curNode = root;
        }

        return root;
    }
};