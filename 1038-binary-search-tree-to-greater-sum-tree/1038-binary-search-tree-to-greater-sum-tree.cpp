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
    
    int sum(TreeNode* root){
        if(root==NULL)return 0;
        int right=sum(root->right);
        int left=sum(root->left);
        return root->val+left+right;
    }
    
    void dfs(TreeNode* root,int &parentSum){
        if(root==NULL)return ;
       dfs(root->right,parentSum);
        parentSum+=root->val;
        root->val=parentSum;
        dfs(root->left,parentSum);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        int parentSum=0;
        dfs(root,parentSum);
        return root;
    }
};