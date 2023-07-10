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
        int minD(TreeNode *tmp, int mini, int cnt)
        {
            if (tmp == NULL)
            {
                return 0;
            }
            if (tmp->left == NULL && tmp->right == NULL)
            {
                return cnt;
            }
            int left = INT_MAX, right = INT_MAX;
            if (tmp->left)
            {
                left = minD(tmp->left, mini, cnt + 1);
            }
            else if (tmp->right)
            {
                right = minD(tmp->right, mini, cnt + 1);
            }
            mini = min({ mini,
                left,
                right });
            return mini;
        }

    int levelOrder(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int level = 1;
        while (!q.empty())
        {
            TreeNode *tmp = q.front();
            q.pop();
            if (tmp == NULL)
            {
                if (q.size() == 0)
                {
                    return level;
                }
                else
                {
                    q.push(NULL);
                    level += 1;
                }
            }
            else
            {
                 if (tmp->left == NULL && tmp->right == NULL)
                {
                    return level;
                }
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
        }
        return level;
    }

    int minDepth(TreeNode *root)
    {

       	// return minD(root, INT_MAX, 1);

       	// sol-2 : levelOrderTraversal

        return levelOrder(root);
    }
};