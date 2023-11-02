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
    int count=0;
    pair<int,int> chk(TreeNode* root)
    {
        if(root==NULL)return {0,0};
        
        pair<int,int>left=chk(root->left);
        pair<int,int>right=chk(root->right);
        
        int totalSum=left.first+right.first+root->val;
        int Nodecount=left.second+right.second+1;
        
        if(root->val==totalSum/(Nodecount))count+=1;
        
        return {totalSum,Nodecount};
     
    }
    int averageOfSubtree(TreeNode* root) {
        pair<int,int>ans= chk(root);
        return count;
    }
};