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
    bool chk(TreeNode* root){
        if(root==nullptr)return false;
        if(root->left==nullptr||root->right==nullptr){
            return root->val;
        }
        if(root->val==2)return (chk(root->left))||chk(root->right);
        else return (chk(root->left))&chk(root->right);
    }
    
    bool evaluateTree(TreeNode* root) {
      
       return chk(root);
    }
    
};