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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>freq;
        vector<int>mode;
        queue<TreeNode*>q;
        if(root)q.push(root);
        int maxi=0;
        while(!q.empty()){
            TreeNode* fnode=q.front();
            q.pop();
            freq[fnode->val]+=1;
            maxi=max(maxi,freq[fnode->val]);
            if(fnode->left)q.push(fnode->left);
            if(fnode->right)q.push(fnode->right);
        }
        for(auto &it:freq){
            if(it.second==maxi){
                mode.push_back(it.first);
            }
        }
        return mode;
        
    }
};