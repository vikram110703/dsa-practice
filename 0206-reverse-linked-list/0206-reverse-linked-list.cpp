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
       ListNode* tmp=head;
        ListNode* prev=nullptr;
        while(tmp!=nullptr){
            if(tmp->next==nullptr){
                tmp->next=prev;break;
            }
            else{
                ListNode* nxt=tmp->next;
                tmp->next=prev;
                prev=tmp;
                tmp=nxt;
                
            }
        }
        return tmp;
    }
};