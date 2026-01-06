/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 
    TIME :   O(Nlog(K))
    SPACE :  O(log(K))
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        return mergeRange(lists, 0, lists.size() - 1);
    }

    ListNode* mergeRange(vector<ListNode*>& lists, int left, int right) {
        if (left == right) return lists[left];

        int mid = left + (right - left) / 2;

        ListNode* l1 = mergeRange(lists, left, mid);
        ListNode* l2 = mergeRange(lists, mid + 1, right);

        return mergeTwoLists(l1, l2);
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        if (l1 != NULL) tail->next = l1;
        if (l2 != NULL) tail->next = l2;

        return dummy->next;
    }
};
