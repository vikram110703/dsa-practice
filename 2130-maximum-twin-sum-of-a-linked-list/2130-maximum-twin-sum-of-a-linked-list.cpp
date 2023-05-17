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
class Solution {
public:
    int pairSum(ListNode* head) {
        
        int n=0,ind=0,ans=0;
        ListNode* tmp=head;
        while(tmp)
        {
            n+=1;tmp=tmp->next;
        }
        
        tmp=head;
        unordered_map<int,int>mpp;
        while(tmp!=NULL)
        {
            if(ind<n/2)
            {
                
            mpp[ind++]=tmp->val;
            }
            else
            {
                mpp[n-1-ind]+=tmp->val;
                ans=max(ans,mpp[n-1-ind]);
                ind+=1;
            }
            tmp=tmp->next;
        }
        return ans;
        
    }
};