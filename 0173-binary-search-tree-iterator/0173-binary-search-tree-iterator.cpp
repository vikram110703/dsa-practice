/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    vector<int>ans;
    int currentIndex=0;

    BSTIterator(TreeNode* root) {
    //  store all the nodes of tree in vector ans
        inOrder(root,ans);
    }
    
    int next() {
        return ans[currentIndex++];
        //return current element of vector ans increase the currentIndex
    }
    
    bool hasNext() {
        if(currentIndex>=ans.size())return false;
        else return true;
    }

    void inOrder(TreeNode* root,vector<int>&ans)
    {
        if(root==NULL)return;
        inOrder(root->left,ans);
        ans.push_back(root->val);
        inOrder(root->right,ans);
    }
};
