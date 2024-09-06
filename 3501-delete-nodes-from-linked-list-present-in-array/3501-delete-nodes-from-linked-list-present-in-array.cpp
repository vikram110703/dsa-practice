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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        sort(nums.begin(),nums.end());

        while(nums.size()> 0 && temp!=NULL)
        {
                int val=temp->val;
                auto it=lower_bound(nums.begin(),nums.end(),val)-nums.begin();

                if(it!=nums.size() && nums[it]==val)// condition to remove node
                {
                    if(prev==NULL)// first node
                    {
                        head=temp->next;
                        temp=temp->next;
                    }
                    else
                    {
                        prev->next=temp->next;
                        temp=temp->next;
                    }
                }
                else// no need to remove this node 
                {
                    prev=temp;
                    temp=temp->next;
                }
        }

        return head;
    }
};