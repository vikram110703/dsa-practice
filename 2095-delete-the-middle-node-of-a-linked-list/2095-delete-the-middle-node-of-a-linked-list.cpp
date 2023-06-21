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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev=NULL;
        // only 1 node
        if(slow->next==NULL)return NULL;
        
        while(fast->next!=NULL&&fast->next->next!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast->next!=NULL)
        {
            prev=slow;
            slow=slow->next;
        }
        prev->next=slow->next;
        return head;
    }
};