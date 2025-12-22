class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        dfs(root, ans);
        return ans;
    }

private:
    int dfs(TreeNode* root, int &ans) {
        if (!root) return 0;

        // Ignore negative paths
        int left = max(0, dfs(root->left, ans));
        int right = max(0, dfs(root->right, ans));

        // Path passing through this node
        ans = max(ans, left + right + root->val);

        // Return best downward path
        return root->val + max(left, right);
    }
};
