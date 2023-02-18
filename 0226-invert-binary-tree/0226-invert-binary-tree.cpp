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
    
    void change(TreeNode* tmp)
    {
        if(tmp==NULL)return;
        TreeNode* left=tmp->left;
         TreeNode* right=tmp->right;
        tmp->left=right;
        tmp->right=left;
       if(tmp->left) change(tmp->left);
        if(tmp->right)change(tmp->right);
    }
    
public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* tmp=root;
        change(tmp);
        return root;
        
    }
};