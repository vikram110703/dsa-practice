/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:

       TreeNode* construct(vector<int> &inorder, vector<int> &postorder, int &rootIndx, int strt, int end)
{
    if (rootIndx < 0 || strt < 0 || end >= inorder.size() || strt > end) return NULL;
    TreeNode * tmp = new TreeNode(postorder[rootIndx]);

    // find index of root element in inorder 
    int indx;
    for (int i = 0; i < inorder.size(); i++)
    {
        if (inorder[i] == postorder[rootIndx])
        {
            indx = i;
            break;
        }
    }
    rootIndx -= 1;
           
           // construct right subtree
    tmp->right = construct(inorder, postorder, rootIndx, indx + 1, end);
    // construct left subtree
    tmp->left = construct(inorder, postorder, rootIndx, strt, indx - 1);
    
    return tmp;
}

    TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
       
        int rootIndx=n-1;
        return construct(inorder, postorder, rootIndx, 0, n - 1);
        
    }
};