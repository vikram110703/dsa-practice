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
    void inOrder(TreeNode* root,vector<int>&inOrderNodes)
    {
        if(root==NULL)return;
        inOrder(root->left,inOrderNodes);
        inOrderNodes.push_back(root->val);
        //right call
        inOrder(root->right,inOrderNodes);
    }
    
    int getMinimumDifference(TreeNode* root) {
        
        int mini=INT_MAX;
        vector<int>inOrderNodes;
        
        inOrder(root,inOrderNodes);
        //inOrder is sorted in bst
        for(int i=1;i<inOrderNodes.size();i++)
        {
            mini=min(mini,inOrderNodes[i]-inOrderNodes[i-1]);
        }
        return mini;
        
        
        
    }
};