/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),                   right(right) {}
 * };
 */
class Solution {
public:
    int maxDiff=0;
    void dfs(TreeNode* root,int mini,int maxi){
       if(root==NULL)return;
        mini=min(mini,root->val);
        maxi=max(maxi,root->val);
        maxDiff=max({maxDiff,abs(root->val-mini),abs(root->val-maxi)});
        dfs(root->left,mini,maxi);
        dfs(root->right,mini,maxi);
       
    }
    
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL)return 0;
        int mini=root->val,maxi=root->val;
        dfs(root,mini,maxi);
        return maxDiff;
    }
};