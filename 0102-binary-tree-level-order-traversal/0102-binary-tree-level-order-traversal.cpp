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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        levelOrder(root,ans);
        return ans;
    }
    
    void levelOrder(TreeNode*root,vector<vector<int>>&ans)
    {
        if(root==nullptr)return;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>tmp;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* fnode=q.front();
                q.pop();
                tmp.push_back(fnode->val);
                if(fnode->left)q.push(fnode->left);
                if(fnode->right)q.push(fnode->right);
            }
            ans.push_back(tmp);
        }
    }
    
};