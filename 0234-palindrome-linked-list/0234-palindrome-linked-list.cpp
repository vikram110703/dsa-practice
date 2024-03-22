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
    ListNode* reverse(ListNode* temp){
        ListNode*prev=nullptr,*nxt=nullptr;
        while(temp!=nullptr){
            nxt=temp->next;
            temp->next=prev;
            prev=temp;
            if(!nxt)break;
            temp=nxt;
        }  
        
        return temp;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head,*fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast)slow=slow->next;//odd length
        ListNode* reversedList=reverse(slow);
        while(head!=nullptr&&reversedList!=nullptr){
            // cout<<head->val<<" "<<reversedList->val<<endl;
            if(head->val!=reversedList->val)return false;
            head=head->next;
            reversedList=reversedList->next;
        }
        return true;
        
    }
};