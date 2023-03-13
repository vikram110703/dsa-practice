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
    
    bool chk(TreeNode* a,TreeNode* b)
    {
        if(a!=NULL&&b!=NULL)
        {
            bool cond=(a->val==b->val);
            bool l=chk(a->left,b->right);
            bool r=(chk(a->right,b->left));
            if(cond==false||l==false||r==false)return false;
            else return true;
        }
        else if(a!=NULL||b!=NULL)return false;
        return true;
    }
    
    bool isSymmetric(TreeNode* root) {
        return chk(root->left,root->right);
        
    }
};