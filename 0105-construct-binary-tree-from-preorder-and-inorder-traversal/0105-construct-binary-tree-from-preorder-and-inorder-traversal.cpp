/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 *right(right) {}
 *};
 */
class Solution {
public:
    TreeNode* build(int &rootIndex, int start, int end, vector<int>& pre,
        vector < int>& in, unordered_map<int, int>& mpp) {
        if (rootIndex >= pre.size() || start > end || start>pre.size() || end<0)
            return NULL;

        int rootVal = pre[rootIndex++];
        int ind = mpp[rootVal]; // current root val index in in_order

        TreeNode* root = new TreeNode(rootVal);
        root->left = build(rootIndex, start, ind - 1, pre, in,mpp); // subTree range start->ind-1
        root->right =build(rootIndex, ind + 1, end, pre, in, mpp); // ind+1->end
        return root;
    }

    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        // pre : root - left - right // assume rootIndex
        // in : left - root - right
        // we will find the root of every subtree from pre,
        // respective left and right sub tree from in order(left: rootIndex-1,
        // right:rootInd+1)
        int n = pre.size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++)
            mpp[in[i]] = i;
        int rootIndex = 0; // first val in preorder is root of tree

        return build(rootIndex, 0, n-1, pre, in, mpp);
        // start,end  is the range of subtree
    }
};