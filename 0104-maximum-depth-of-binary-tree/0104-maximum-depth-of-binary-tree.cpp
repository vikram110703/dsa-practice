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
    int maxDepth(TreeNode* root) {
       return dfs(root);
    }
    int dfs(TreeNode* node) {
       if(node==NULL)return 0;
       int leftDepth= 1+dfs(node->left);
       int rightDepth= 1+dfs(node->right);
       return max(leftDepth,rightDepth);
    }
};