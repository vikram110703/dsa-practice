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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
     TreeNode* tmp=root;
        if(tmp==NULL)return {};
        queue<TreeNode*>q;
        q.push(tmp);
        q.push(NULL);
        vector<vector<int>>v;
        vector<int>vv;
        while(!q.empty())
        {
            TreeNode* fnode=q.front();
            q.pop();
            if(fnode==NULL)
            {
                v.push_back(vv);
                vv.clear();
                if(!q.empty())q.push(NULL);
                else break;
            }
            else
            {
                vv.push_back(fnode->val);
               if(fnode->left) q.push(fnode->left);
               if(fnode->right) q.push(fnode->right);
            }
        }
        
        reverse(v.begin(),v.end());
        return v;
        
    }
};