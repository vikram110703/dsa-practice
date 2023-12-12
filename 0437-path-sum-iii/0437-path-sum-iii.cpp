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
    int cnt=0;
    unordered_map<long ,int>mpp;
    void dfs(TreeNode *root,long currSum,int targetSum){
        if(!root)return ;
        currSum+=(root->val);
        if(currSum==targetSum)cnt+=1;
        if(mpp.find(currSum-targetSum)!= mpp.end())cnt+=mpp[currSum-targetSum];
  
        mpp[currSum]+=1;
        dfs(root->left,currSum,targetSum);
        dfs(root->right,currSum,targetSum);
        mpp[currSum]-=1;
    
    }
    int pathSum(TreeNode* root, int targetSum) {
        dfs(root,0,targetSum);
        return cnt;
    }
};