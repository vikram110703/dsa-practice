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
    int ans=0;
    int cal(TreeNode* root,bool left){
        if(root==NULL)return 0;
        int l=cal(root->left,true)+1;
        int r=cal(root->right,false)+1;
        ans=max({ans,l,r});
        return left?r:l;
    }

    int longestZigZag(TreeNode* root) {
       ans=max(ans,cal(root,true));
        return ans-1;
    }
};