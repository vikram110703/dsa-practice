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
    
    void level(TreeNode*&root,vector<vector<int>>&ans)
    { 
        queue<TreeNode*> q;
        if(root==NULL)return;
        q.push(root);
        q.push(NULL);
        TreeNode* fnode;
        bool flg=true;
        vector<int>v;
        while(!q.empty())
        {
            fnode=q.front();q.pop();
            if(fnode==NULL)
            {
                if(flg)
                {
                    ans.push_back(v);
                    v.clear();
                }
                else
                {
                    reverse(v.begin(),v.end());
                    ans.push_back(v);
                    v.clear();
                }
                flg=!flg;
                if(!q.empty())q.push(NULL);
            }
            else
            {
                v.push_back(fnode->val);
                if(fnode->left)q.push(fnode->left);
                if(fnode->right)q.push(fnode->right);
                
            }
            
        }
    }
    
    
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        // TreeNode* tmp=root;
        level(root,ans);
        return ans;
        
    }
};