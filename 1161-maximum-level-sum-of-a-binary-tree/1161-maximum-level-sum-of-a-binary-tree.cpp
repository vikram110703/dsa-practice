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
    int maxLevel=0,maxSum=INT_MIN;
    void bfs(TreeNode* root,int level){
        queue<TreeNode*>q;
        if(root==NULL)return ;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            int currSum=0;
            for(int i=0;i<sz;i++){
                TreeNode* fnode=q.front();
                q.pop();
                currSum+=fnode->val;
                if(fnode->left)q.push(fnode->left);
                if(fnode->right)q.push(fnode->right);
            }
            if(currSum>maxSum){
                maxSum=currSum;
                maxLevel=level;
            }
            level+=1;
        }
    }
    int maxLevelSum(TreeNode* root) {
        bfs(root,1);
        return maxLevel;
    }
};