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
    ListNode* mergeInBetween(ListNode* l, int a, int b, ListNode* ll) {
        int cnt=0;
        ListNode* tmp=l;
        ListNode* prev=NULL;
        ListNode* after=NULL;
        while(tmp!=NULL){
            if(cnt==a-1){
              prev=tmp;
            }
           else if(cnt==b+1){
               after=tmp;
               break;
           }
            cnt+=1;tmp=tmp->next;
        }
        
       prev->next=ll;
        while(ll->next!=nullptr)ll=ll->next;
        if(ll!=NULL)ll->next=after;
        return l;
           
    }
};