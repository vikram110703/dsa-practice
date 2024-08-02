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
        if((a==nullptr&&b!=nullptr)||(b==nullptr&&a!=nullptr))return false;
        else if(a!=NULL||b!=NULL){
            bool cond1=a->val==b->val;
            bool cond2=chk(a->left,b->right);
            bool cond3=chk(a->right,b->left);
            if(cond1==true&&cond2==true&&cond3==true)return true;
            else return false;
        }
        else// a=null : b=null
        {
            return true;
        }
    }

};