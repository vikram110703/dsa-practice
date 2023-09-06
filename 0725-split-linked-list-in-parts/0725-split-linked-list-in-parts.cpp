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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        ListNode*tmp=head;
        while(tmp!=NULL){
            n+=1;
            tmp=tmp->next;
        }
        int rem=n%k,sz=n/k, j=0;
        vector<ListNode*>v(k);
        int extra=0,currSize=0;
        tmp=NULL;
        // cout<<head->val<<endl;
        while(head!=NULL){
            if(rem>0)extra=1;
            else extra=0;
            if(currSize==0)v[j++]=head;
            if(currSize+1>sz+extra){
                if(rem>0)rem-=1;
                v[j++]=head;
                tmp->next=NULL;
                currSize=1;
            }
            else currSize+=1;
            tmp=head;
            head=head->next;
        }
        return v;
    }
};