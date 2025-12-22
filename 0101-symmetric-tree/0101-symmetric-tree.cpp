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
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)return true;
       return chk(root->left,root->right);
    }

private:
   bool chk(TreeNode* a,TreeNode*b)
    {
        if(a==NULL && b==NULL)return true;
        if((a==NULL && b!=NULL) || (a!=NULL && b==NULL))return false;
        if(a->val!=b->val)return false;

        //both are not null
        bool op1=chk(a->left,b->right);
        bool op2=chk(a->right,b->left);

        return (op1 && op2);
    }

};