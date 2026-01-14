class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        ListNode* tmp=head;
        ListNode dummy(0);
        ListNode *tail=&dummy;

        for (int i = 1; i < left; i++) {
           tail->next=tmp;
           tmp=tmp->next;
           tail=tail->next;
        }
        //reverse start from tmp and  previous list is till tail
        ListNode* prev=NULL;
        //first node of middle list; 
        cout<<tmp->val<<endl;
        ListNode* firstNodeOfMiddle=NULL;
        for (int i = 0; i < right - left+1; i++) {
            ListNode* nextNode=tmp->next;
            tmp->next=prev;
            prev=tmp;
            if(!firstNodeOfMiddle)firstNodeOfMiddle=prev;
            tmp=nextNode;
        }
        //not tmp is the pointing to 3rd list and prev is head of reversed list

        tail->next=prev;
        firstNodeOfMiddle->next=tmp;
        // cout<<tail->val<<" "<<firstNodeOfMiddle->val<<" "<<tmp->val<<endl;

        return dummy.next;
    }
};
