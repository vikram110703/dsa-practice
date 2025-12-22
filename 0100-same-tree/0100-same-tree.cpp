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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p,q);
    }
    private :
    bool dfs(TreeNode* p,TreeNode* q)
    {
        if((p==NULL && q!=NULL) || (q==NULL && p!=NULL))return false;
        if(p!=NULL && q!=NULL && p->val!=q->val)return false;
        if(p==NULL && q==NULL)return true;
        bool a=dfs(p->left,q->left);
        bool b=dfs(p->right,q->right);
        return (a && b);
    }

};