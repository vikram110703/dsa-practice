/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int>ans;
    void dfs(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent){
        if(root->left){
            parent[root->left]=root;
            dfs(root->left,parent);
        }
        if(root->right){
            parent[root->right]=root;
            dfs(root->right,parent);
        }
        return;
    }

    void dfs2(TreeNode* root,int distance,int &k,unordered_map<TreeNode*,TreeNode*>&parent,unordered_map<TreeNode*,bool>&visited){
        visited[root]=true;
        cout<<root->val<<" "<<distance<<endl;
        if(distance==k){
            ans.push_back(root->val);
            return;
        }
        if(distance>k)return;

        if(root->left && visited[root->left]==false){
            dfs2(root->left,distance+1,k,parent,visited);
        }
        if(root->right && visited[root->right]==false){
            dfs2(root->right,distance+1,k,parent,visited);
        }
        if(parent.find(root)!=parent.end() && visited[parent[root]]==false){
            dfs2(parent[root],distance+1,k,parent,visited);
        }
        return;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        unordered_map<TreeNode*,bool>visited;
        dfs(root,parent); // fill the parent array

        dfs2(target,0,k,parent,visited);
        return ans;

    }
};