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

    TreeNode* convert(vector<int> &v, int strt, int end)
    {
        if (strt > end) return NULL;
        int mid = strt + (end - strt) / 2;
        TreeNode *root = new TreeNode(v[mid]);
        root->left = convert(v, strt, mid - 1);
        root->right = convert(v, mid + 1, end);
        return root;
    }

    public:
        TreeNode* sortedArrayToBST(vector<int> &v)
        {
            int n = v.size();

            return convert(v, 0, n - 1);
        }
};