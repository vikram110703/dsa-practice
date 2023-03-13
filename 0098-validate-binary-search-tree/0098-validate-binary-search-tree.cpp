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

        bool chk(TreeNode *root,long long mini,long long maxi)
        {
            if (root == NULL) return true;
            long long  rootData = (root->val*1ll);
            bool cond=(rootData>mini&&rootData<maxi);
            bool left=chk(root->left,mini,rootData);
            bool right=chk(root->right,rootData,maxi);
            if(cond&&left&&right)return true;
            else return false;
            
        }

    bool isValidBST(TreeNode *root)
    {
        // cout<<INT_MIN<<" "<<INT_MAX<<endl;
        // [2147483647]
            return chk(root,-1*10000000000,10000000000);
    }
};