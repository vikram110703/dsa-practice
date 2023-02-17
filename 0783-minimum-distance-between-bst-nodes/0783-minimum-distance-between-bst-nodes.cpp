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
        void level(TreeNode* &tmp, vector<int> &v)
        {
            if (tmp == NULL) return;
            v.push_back(tmp->val);
            if (tmp->left) level(tmp->left, v);
            if (tmp->right) level(tmp->right, v);
        }

    int minDiffInBST(TreeNode *tmp)
    {

        // TreeNode *tmp = root;
        vector<int> v;
        level(tmp, v);

        sort(v.begin(), v.end());
        int ans = 100001;
        for (int i = 0; i < v.size() - 1; i++)
        {
            ans = min(ans, v[i + 1] - v[i]);
        }
        v.clear();
        return ans;
    }
};