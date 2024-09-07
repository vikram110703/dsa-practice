/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
class Solution {
public:
    bool isValid=false;

    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(root,head);
    }

    bool dfs(TreeNode* root,ListNode* head)
    {
        if(head==NULL) return true;// matched 
        if(root==NULL) return false;// end with no match 

        bool ans = check(root,head);
        if(ans) return true;

        if(root->left) ans|= dfs(root->left,head);
        if(root->right)ans|= dfs(root->right,head);

        return ans;
    }

    bool check(TreeNode* curr,ListNode* head )
    {
        if(curr->val != head->val) return false;//not matched 
        if(head->next==NULL) return true; // matched and it is end of the list 

        bool ans=false; 
        if(curr->left) ans|= check(curr->left,head->next);
        if(curr->right) ans|= check(curr->right,head->next);

        return ans;
    }
};


// Time Complaxity O(N*N) 