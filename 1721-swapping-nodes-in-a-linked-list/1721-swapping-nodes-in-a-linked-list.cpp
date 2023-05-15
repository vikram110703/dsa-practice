/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* swapNodes(ListNode *head, int k)
        {
            int n = 0;//size 
            ListNode *tmp = head;
            int strt, end;
            while (tmp != NULL)
            {
                n += 1;
                tmp = tmp->next;
            }

            tmp = head;
            int cnt = 1;
            while (cnt <= n)
            {
                if (cnt == k) strt = tmp->val;
                if (cnt == n - k + 1) end = tmp->val;
                tmp = tmp->next;
                cnt += 1;
            }
            tmp = head;
            cnt = 1;
            while (cnt <= n)
            {
               	// swap (strt,end)
                if (cnt == k) tmp->val = end;
                if (cnt == n - k + 1) tmp->val = strt;
                tmp = tmp->next;
                cnt += 1;
            }

            return head;
        }
};