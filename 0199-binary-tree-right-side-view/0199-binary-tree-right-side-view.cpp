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
    int level=0;
    map<int,int>mpp;
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr)return {};
        bfs(root);

        vector<int>ans;
        for(int i=0;i<level;i++)
        {
            ans.push_back(mpp[i]);
        }

        return ans;
    }
    private:
     void bfs(TreeNode* root)
     {
        queue<TreeNode*>q;//{node,level};
        q.push({root});
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* fnode=q.front();
                q.pop();
                mpp[level]=fnode->val;
                if(fnode->left)q.push(fnode->left);
                if(fnode->right)q.push(fnode->right);
            }
            level+=1;
        }
     }
};