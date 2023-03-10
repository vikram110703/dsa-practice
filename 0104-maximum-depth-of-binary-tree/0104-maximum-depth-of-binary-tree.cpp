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
    
    int maxd(TreeNode* tmp)
    {
       if(tmp==NULL)return 0;
        int leftDepth=maxd(tmp->left);
        int rightDepth=maxd(tmp->right);
        
        return max(leftDepth,rightDepth)+1;
        
    }
    
    
public:
    int maxDepth(TreeNode* root) {
        TreeNode* tmp=root;
        return maxd(tmp);
        
        
        
    }
};