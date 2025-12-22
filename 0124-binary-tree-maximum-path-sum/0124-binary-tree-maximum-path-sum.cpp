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
    int maxPathSum(TreeNode* root) {
        int h=dfs(root);
        int maxPath=-1*100000;
        dfs2(root,maxPath);
        return maxPath;
    }
    private:
    int dfs(TreeNode* root){
        if(root==NULL)return -1*100000;
        int left=dfs(root->left);
        int right=dfs(root->right);
        int val=root->val;
        int a=left+val;
        int b=right+val;
        int c=val;
        // cout<<"root : "<<val<<" "<<max({a,b,c})<<endl;
         root->val=max({a,b,c});
         return root->val;
    }
    void dfs2(TreeNode* root,int &maxPath)
    {
        if(root==NULL)return;
        int left=0,right=0;
        if(root->left)left=root->left->val;
        if(root->right)right=root->right->val;
        int val=root->val;
        int a=left+val;
        int b=right+val;
        maxPath=max({maxPath,val,min(a,b)});
        // cout<<"roott : "<<val<<" "<<left<<" "<<right<<" "<<maxPath<<endl;
        dfs2(root->left,maxPath);
        dfs2(root->right,maxPath);
    }

};