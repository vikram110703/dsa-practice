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
    TreeNode* convert(vector<int>&nodes,int strt,int end)
    {
        if(strt>end)return NULL;
        int mid=strt+(end-strt)/2;
        TreeNode* root=new TreeNode(nodes[mid]);
        root->left=convert(nodes,strt,mid-1);
        root->right=convert(nodes,mid+1,end);
        return root;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* tmp=head;
        vector<int>nodes;
        while(tmp!=NULL)
        {
            nodes.push_back(tmp->val);
            tmp=tmp->next;
        }
        return convert(nodes,0,nodes.size()-1);
        
    }
};