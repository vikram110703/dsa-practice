/**
 *Definition for singly-linked list.
 *struct ListNode {
 *int val;
 *ListNode * next;
 *ListNode() : val(0), next(nullptr) {}
 *ListNode(int x) : val(x), next(nullptr) {}
 *ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:

        ListNode* reverse(ListNode *head)
        {
            ListNode *prev = nullptr;
            ListNode *current = head;

            while (current != nullptr)
            {
                ListNode *nextNode = current->next;
                current->next = prev;
                prev = current;
                current = nextNode;
            }

            return prev;
        }

    ListNode* addTwoNumbers(ListNode *a, ListNode *b)
    {
        a = reverse(a);
        b = reverse(b);
        ListNode *ans = NULL;
        int sum = 0, carry = 0;

        while (a != NULL && b != NULL)
        {
            sum = (a->val + b->val) + carry;
            carry = 0;
            ListNode *tmp = new ListNode(sum % 10);
            carry += (sum / 10);
            tmp->next = ans;
            ans = tmp;
            a = a->next;
            b = b->next;
        }
        if (a)
        {
            while (a != NULL)
            {
                sum = a->val + carry;
                carry = 0;
                ListNode *tmp = new ListNode(sum % 10);
                carry += (sum / 10);
                tmp->next = ans;
                ans = tmp;
                a = a->next;
            }
        }
        if (b)
        {
            while (b != NULL)
            {
                sum = b->val + carry;
                carry = 0;
                ListNode *tmp = new ListNode(sum % 10);
                carry += (sum / 10);
                tmp->next = ans;
                ans = tmp;
                b = b->next;
            }
        }
        if(carry)
        {
            ListNode *tmp=new ListNode(1);
            tmp->next=ans;
            ans=tmp;
        }
        
        return ans;
    }
};