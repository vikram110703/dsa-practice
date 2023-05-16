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
    ListNode* swapPairs(ListNode* head) {
        ListNode* tmp=head;
        ListNode* newHead=head;
        if(tmp==NULL)return head;
        ListNode* curr; ListNode* nxt;ListNode* prev=NULL;
        int cnt=1;
        while(tmp!=NULL&&tmp->next!=NULL)
        {
            if(cnt==1)
            {
                ListNode* nxtt;
               
                    nxtt=tmp->next->next;
                    
                
                curr=tmp;
                nxt=tmp->next;
                newHead=nxt;
                newHead->next=curr;
                prev=curr;
                curr->next=nxtt;
                tmp=nxtt;
               
            }
            else
            {
                curr=tmp;
                nxt=tmp->next;
                ListNode* nxtt;
                
                 nxtt=tmp->next->next;
                prev->next=nxt;
                nxt->next=curr;
                prev=curr;
                curr->next=nxtt;
                tmp=nxtt;
            
            }
            cnt+=1;
        }
        return newHead;
        
    }
};