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
    
    void leafSum(TreeNode* root,string s,int &ans)
    {
        if(root==NULL)return ;
        if(root->left==NULL&& root->right==NULL)
        {
            char a=root->val+'0';
            s+=a;
            // cout<<s<<" ";
            ans+=(stoi(s));
            return ;
        }
        s+=(root->val+'0');
        leafSum(root->left,s,ans);
        string ss=s;// for right traversal
        leafSum(root->right,ss,ans);
    }
    int sumNumbers(TreeNode* root) {
        int ans=0;
        string s="";
        leafSum(root,s,ans);
        return ans;
    }
};