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

        int biToInt(string s)
        {
            int n = s.size();
            int ans = 0;
            int cnt = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                if (s[i] == '1')
                {
                    ans += (pow(2, cnt));
                }
                cnt += 1;
            }
            return ans;
        }

    void chk(TreeNode *root, string s, int &ans)
    {
       	if (root == NULL)
       	{
       	    // ans += biToInt(s);
       	    // cout<<s<<" ";
       	    return;
       	}
        if (root->left == NULL && root->right == NULL)
        {
            char a = (root->val) + '0';
            s += a;
            ans += biToInt(s);
            // cout << s << " ";
            return;
        }

        char a = (root->val) + '0';
        s += a;
       	string s2=s;
        chk(root->left, s, ans);
       	chk(root->right, s2, ans);
    }
    int sumRootToLeaf(TreeNode *root)
    {
        int ans = 0;
        string s = "";
        chk(root, s, ans);
        return ans;
    }
};