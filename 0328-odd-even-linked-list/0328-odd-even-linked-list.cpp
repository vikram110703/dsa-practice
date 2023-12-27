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
    ListNode* oddEvenList(ListNode* head) {

        ListNode* h=NULL;
        ListNode* hh=NULL;
        ListNode* t=NULL;
        ListNode* tt=NULL;
        ListNode* lastEven=NULL;

        int cnt=1;
        ListNode* tmp=head;
        while(tmp!=NULL)
        {
            if(cnt%2==0)
            {
                if(hh==NULL)
                {
                    hh=tmp;
                    tt=tmp;
                    lastEven=tmp;
                }
                else
                {
                    // prev=tt;
                    tt->next=tmp;
                    tt=tmp;
                    lastEven=tmp;

                }
            }
            else
            {
                 if(h==NULL)
                {
                    h=tmp;
                    t=tmp;
                }
                else
                {
                    t->next=tmp;
                    t=tmp;

                }
            }
            cnt+=1;tmp=tmp->next;
        }
        
        if(h==NULL||hh==NULL)return h;
        if(cnt%2==0){
            lastEven->next=NULL;
        }
        
       t->next=hh;
        return h;
        
    }
};