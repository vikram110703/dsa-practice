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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        return bfs(root);
    }
    private:
    vector<vector<int>>bfs(TreeNode* root)
    {
        bool dir=true;
        //dir : true->L to R and false: R to L
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(root==nullptr)return ans;
        q.push(root);//L to R 
        dir=false;// now  new node will be R to L
        while(!q.empty())
        {
            int size=q.size();
            vector<int>tmp;// to store the childs of current level
            for(int i=0;i<size;i++)
            {
              TreeNode* fnode=q.front();
              tmp.push_back(fnode->val);
              q.pop();
                if(fnode->left)q.push(fnode->left);
                if(fnode->right)q.push(fnode->right); 
            }
            if(dir==true)reverse(tmp.begin(),tmp.end());
            ans.push_back(tmp);
            dir=!dir;//change the direction for next round
        }
        
        return ans;
    }
};