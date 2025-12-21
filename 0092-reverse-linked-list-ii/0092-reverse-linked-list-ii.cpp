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

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        ListNode *first=new ListNode(0);
        ListNode* firsttail=first;
        ListNode* second=NULL;
        ListNode* third=NULL;

        for(int i=1;i<left;i++){
            firsttail->next=head;
            head=head->next;
            firsttail=firsttail->next;
        }
        firsttail->next=NULL;
        ListNode* secondtail=head;//now tail is pointing to middle list
        for(int i=left;i<right;i++){
            secondtail=secondtail->next;
        }
        third=secondtail->next;
        secondtail->next=NULL;

        //first -> reverse(head) -> third

        firsttail->next=reverseList(head);
        while(firsttail->next!=NULL)firsttail=firsttail->next;
        firsttail->next=third;
        return first->next;
    }
};
