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
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return NULL ;
        if(root->val==key){
           if(!root->left && !root->right) return NULL;      
                if (!root->left || !root->right)
                    return root->left ? root->left : root->right;  
				// root ke left me jo max value hai usko root->val bana do baaki kuchh mat karo                         
                TreeNode* temp = root->left;                      
                while(temp->right != NULL) temp = temp->right;     
                root->val = temp->val;                            
                root->left = deleteNode(root->left, temp->val);  	
        }

        if(root->val>key)root->left=deleteNode(root->left,key);
        else root->right=deleteNode(root->right,key);
        
        return root;
    }
};