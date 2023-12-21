/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<int,int>level;
    map<TreeNode*,TreeNode*>parent;
    void dfs(TreeNode* root,TreeNode* p=NULL,int l=0){
        if(root==NULL)return;
       parent[root]=p;
        level[root->val]=l;
        if(root->left)dfs(root->left,root,l+1);
        if(root->right)dfs(root->right,root,l+1);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        dfs(root);
        int lev1=level[p->val];
        int lev2=level[q->val];
        
            while(lev1>lev2){
                p=parent[p];
                lev1=level[p->val];
            }
        while(lev2>lev1){
            q=parent[q];
            lev2=level[q->val];
        }
        
            while(p!=q){
                if(p==root||q==root){
                    return root;
                }
                p=parent[p];
                q=parent[q];
            }
            return p;
        
    }
};