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
    vector<double> averageOfLevels(TreeNode* root) {
      TreeNode* tmp=root;
        if(tmp==NULL)return {};
        queue<TreeNode*>q;
        q.push(tmp);
        q.push(NULL);
        vector<double>v;
        // vector<int>vv;
        double sum=0;int cnt=0;
        
        while(!q.empty())
        {
            TreeNode* fnode=q.front();
            q.pop();
            if(fnode==NULL)
            {
                
                v.push_back(double(sum*1.0)/(cnt*1.0));
                cnt=0;
                sum=0;
                if(!q.empty())q.push(NULL);
                else break;
            }
            else
            {
                // vv.push_back(fnode->val);
                sum+=(fnode->val*1.0);cnt+=1;
               if(fnode->left) q.push(fnode->left);
               if(fnode->right) q.push(fnode->right);
            }
        }
        
        return v;
    }
};