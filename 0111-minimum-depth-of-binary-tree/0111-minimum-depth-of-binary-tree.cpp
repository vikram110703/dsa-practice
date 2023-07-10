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
    int minD(TreeNode* tmp,int mini,int cnt)
    {
        if(tmp==NULL)
        {
            return 0;
        }
        if(tmp->left==NULL&&tmp->right==NULL)
        {
            return cnt;
        }
        int left=INT_MAX,right=INT_MAX;
        if(tmp->left){
            left=minD(tmp->left,mini,cnt+1);
        }
        if(tmp->right)
        {
            right=minD(tmp->right,mini,cnt+1);
        }
        mini=min({mini,left,right});
        return mini;
    }
    
    int minDepth(TreeNode* root) {
        
        return minD(root,INT_MAX,1);
    }
};