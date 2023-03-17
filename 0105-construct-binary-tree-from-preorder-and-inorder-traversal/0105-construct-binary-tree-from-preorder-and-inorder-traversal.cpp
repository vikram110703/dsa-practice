/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        TreeNode* build(vector<int> &pre, vector<int> &in, int &index, int strt, int end, map< int, int> &mpp)
        {
            if (index > in .size() || strt > end || strt > in .size()) return NULL;
            int val = pre[index++];
           	// val ka index in preorder 
            int valIndex = mpp[val];
            TreeNode *root = new TreeNode(val);
            root->left = build(pre, in, index, strt, valIndex - 1, mpp);
            root->right = build(pre, in, index, valIndex + 1, end, mpp);
            return root;
        }

    TreeNode* buildTree(vector<int> &pre, vector<int> &in)
    {
        int n = in .size();
        map<int, int> mpp;
        for (int i = 0; i < n; i++)
        {
            mpp[ in[i]] = i;
        }
        int index = 0;
        return build(pre, in, index, 0, n - 1,mpp);
    }
    };