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
    
    bool isCompleteTree(TreeNode* root) {
// level order traversal (l to r) if we find a null node  and after that a non null //then return false;
       
        queue<TreeNode*>q;
        q.push(root);
        bool flg=false;
        while(!q.empty())
        {
            TreeNode* tmp=q.front();
            q.pop();
            
            if(tmp!=NULL)
            {
                if(flg==true)return false;
                q.push(tmp->left);
                q.push(tmp->right);
            }
            else
            {
                flg=true;
            }
        }
        return true;
        
    }
};