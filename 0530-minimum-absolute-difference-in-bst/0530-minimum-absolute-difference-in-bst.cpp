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
    void inorder(TreeNode* root,int &mini,int &pre){
        if(root==NULL)return;
        inorder(root->left,mini,pre);
        mini=min(mini,abs(root->val-pre));
        pre=root->val;
        inorder(root->right,mini,pre);
    }

    int getMinimumDifference(TreeNode* root) {
        int mini=INT_MAX;
        int pre=INT_MAX;
        inorder(root,mini,pre);
        return mini;
    }
};

//in-order : left-root-right