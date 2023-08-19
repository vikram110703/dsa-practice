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
    map<TreeNode*,int>Depth;
    int depth(TreeNode* root)
    {
        if(root==NULL)return 0;
        if(Depth.count(root))return Depth[root];
        int left=depth(root->left);
        int right=depth(root->right);
        Depth[root]=max(left,right)+1;
        return Depth[root];
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root==NULL)return NULL;
        int left=depth(root->left);
        int right=depth(root->right);
        if(left==right)return root;
        if(left>right)return lcaDeepestLeaves(root->left);
        else return lcaDeepestLeaves(root->right);
        
    }
};