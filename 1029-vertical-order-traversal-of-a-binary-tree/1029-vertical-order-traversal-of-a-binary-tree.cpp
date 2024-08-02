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
    int left=INT_MAX,right=0,level=0;
    map<int,vector<pair<int,int>>>mpp;//[x]->{y,val}

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==NULL)return {};
        bfs(root);

        vector<vector<int>>ans(right-left+1);
        int tmp=left;
        for(int i=0;i<(right-tmp+1);i++)
        {
            sort(mpp[left].begin(),mpp[left].end());
            for(auto &it:mpp[left])
            {
              ans[i].push_back(it.second);
            }
            left+=1;
        }

        return ans;
    }
    private:
        void bfs(TreeNode* root)
        {
            if(root==NULL)return;
            queue<pair<TreeNode*,int>>q;
            q.push({root,0});//{root,x}
            while(!q.empty())
            {
                int size=q.size();
                for(int i=0;i<size;i++)
                {
                    TreeNode* fnode=q.front().first;
                    int x=q.front().second;
                    q.pop();
                    left=min(left,x);
                    right=max(right,x);
                    mpp[x].push_back({level,fnode->val});
                    if(fnode->left)
                    {
                        q.push({fnode->left,x-1});
                    }
                    if(fnode->right)
                    {
                        q.push({fnode->right,x+1});
                    }
                    
                }
                level+=1;
            }


        }
};