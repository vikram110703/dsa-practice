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

        void storenodes(TreeNode *root, vector<int> &ans)
        {
            if (root == NULL) return;
            ans.push_back(root->val);
            storenodes(root->left, ans);
            storenodes(root->right, ans);
        }

    bool findTarget(TreeNode *root, int k)
    {
        vector<int> ans;
        bool plk = 0;
        unordered_map<int, int> mpp;
        storenodes(root, ans);	// call to store nodes
        for (int i = 0; i < ans.size(); i++)
        {
            mpp[ans[i]] += 1;
        }
        for (int i = 0; i < ans.size(); i++)
        {
            if (mpp.count(k - ans[i]))
            {
                if (k - ans[i] == ans[i])
                {
                    if (mpp[ans[i]] > 1)
                    {
                        plk = 1;
                        break;
                    }
                }
                else
                {
                    plk = 1;
                    break;
                }
            }
        }
        return plk;
    }
};