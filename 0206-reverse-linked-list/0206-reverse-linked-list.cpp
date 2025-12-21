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
    ListNode* reverseList(ListNode* head) {
      ListNode* curr=head;
      ListNode* prev=NULL;

      while(curr!=NULL && curr->next!=NULL){
        if(curr->next->next==NULL){
            // last two nodes
            ListNode* nxt=curr->next;
            curr->next=NULL;
            nxt->next=curr;
            curr->next=prev;
            return nxt;
        }
        else{
            ListNode* nxt=curr->next;
            ListNode* nxtTOnext=curr->next->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
      }
      return head;
    }
};