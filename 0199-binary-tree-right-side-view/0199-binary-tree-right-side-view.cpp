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
    vector<int>ans;
    
    void bfs(TreeNode* root){
        queue<TreeNode*>q;
        if(root==NULL)return;
        q.push(root);
        
        while(!q.empty()) {
            int sz=q.size();
            for(int i=0;i<sz;i++){
                 TreeNode* fnode=q.front();
            q.pop();
                if(i==sz-1)
            ans.push_back(fnode->val);
            if(fnode->left)q.push(fnode->left);
            if(fnode->right)q.push(fnode->right);
            }
           
        }
    }
    
    vector<int> rightSideView(TreeNode* root) {
        bfs(root);
        return ans;
    }
};