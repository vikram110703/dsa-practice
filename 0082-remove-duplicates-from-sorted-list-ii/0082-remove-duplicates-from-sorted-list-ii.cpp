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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        ListNode* tail=&dummy;
        ListNode* prev=NULL;
        ListNode* tmp=head;
        while(tmp){
            if(tmp->next && tmp->next->val==tmp->val){
                int currVal=tmp->val;
                while(tmp && tmp->val==currVal)tmp=tmp->next;
                //if last node is duplicate then we have to add null to dummy node
                // ex: 3,4,4,5,5,5
                if(tmp==NULL && prev){
                    prev->next=NULL;
                }
                continue;
            }
            //now this is a unique node or null
            if(tmp!=NULL){
                tail->next=tmp;
                tail=tail->next;
                prev=tail;
                tmp=tmp->next;
            }
        }

        return dummy.next;

    }
};