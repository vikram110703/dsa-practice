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
    map<TreeNode*,TreeNode*>parent;
    map<TreeNode*,bool>viss;
    int time=0;
    TreeNode* tmp;
    void dfs(TreeNode* root,int start){
        if(root==NULL)return;
        if(root->val==start){
            tmp=root;
        }
        if(root->left){
            parent[root->left]=root;
            dfs(root->left,start);
        }
        if(root->right){
            parent[root->right]=root;
            dfs(root->right,start);
        }
    }
    
    void bfs(TreeNode* root){
        if(root==NULL)return;
        queue<TreeNode*>q;
        q.push(root);
        // viss[root]=true;
        // cout<<root->val<<" ";
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* fnode=q.front();
                // cout<<fnode->val<<endl;
                q.pop();
                viss[fnode]=true;
        if(fnode->left&&viss[fnode->left]==false)
        {
            q.push(fnode->left);
        }
        if(fnode->right&&viss[fnode->right]==false)
        {
            q.push(fnode->right);
        }
        if(parent[fnode]!=NULL&&viss[parent[fnode]]==false){
            q.push(parent[fnode]);
            // viss[parent[fnode]]=true;
        }
            }
            time+=1;
        }
        
    }
    
    int amountOfTime(TreeNode* root, int start) {
        parent[root]=root;
        dfs(root,start);
        // cout<<tmp->val<<endl;
        bfs(tmp);
        
        return max(time-1,0);
        
    }
};