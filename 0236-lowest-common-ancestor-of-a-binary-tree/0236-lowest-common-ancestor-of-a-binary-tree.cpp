class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_map<TreeNode*, int> level;

    void dfs(TreeNode* root, TreeNode* p = nullptr, int l = 0) {
        if (!root) return;
        parent[root] = p;
        level[root] = l;
        dfs(root->left, root, l + 1);
        dfs(root->right, root, l + 1);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root);

        while (level[p] > level[q]) p = parent[p];
        while (level[q] > level[p]) q = parent[q];
        //both are same level
        while (p != q) {
            p = parent[p];
            q = parent[q];
        }
        return p;
    }
};
