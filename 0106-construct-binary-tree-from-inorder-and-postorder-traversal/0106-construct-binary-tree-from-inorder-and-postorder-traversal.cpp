/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:

        TreeNode* construct(vector<int> &inorder, vector<int> &postorder, int &rootIndx, int strt, int end,map<int,int>&mpp)
        {
            if (rootIndx < 0 || strt < 0 || end >= inorder.size() || strt > end) return NULL;
            TreeNode *tmp = new TreeNode(postorder[rootIndx]);

           	// find index of root element in inorder 
            int indx=mpp[postorder[rootIndx]];
      
            
            rootIndx -= 1;

           	// construct right subtree
            tmp->right = construct(inorder, postorder, rootIndx, indx + 1, end,mpp);
           	// construct left subtree
            tmp->left = construct(inorder, postorder, rootIndx, strt, indx - 1,mpp);

            return tmp;
        }

    TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        map<int,int>mpp;
        for(int i=0;i<n;i++)
        {
            mpp[inorder[i]]=i;
        }

        int rootIndx = n - 1;
        return construct(inorder, postorder, rootIndx, 0, n - 1,mpp);
    }
};