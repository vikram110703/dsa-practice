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
    int addNum(int a,string b){
       if(b==""|| b[0]==' ')return 0;
       return a+stoi(b);
    }
    void dfs(TreeNode* root,string s,int &ans){
        if(root==NULL) return;
        s+=to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            ans=addNum(ans,s);
            return;
        }
        dfs(root->left,s,ans);
        dfs(root->right,s,ans);
    }

    int sumNumbers(TreeNode* root) {
        if(root==NULL)return 0;
        int ans=0;
        dfs(root,"",ans);
        return ans;
    }
};