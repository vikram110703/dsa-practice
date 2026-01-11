// 1. Using 2pointer / fast-slow pointer find the middle node of the list.
// 2. Now call mergeSort for 2 halves.
// 3. Merge the Sort List (divide and conqueror Approach)

class Solution {
public:
     ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *slow = head, *fast = head, *prev = NULL;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);
        //we are not calling merge(l1,l2) directly becaue l1 and l2 are not sorted
        //first we will use divide and conqure
        return merge(l1, l2);
    }

private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);//stack allocation(no heap alloaction), no memory leak
        ListNode *curr = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if (l1) curr->next = l1;
        if (l2) curr->next = l2;
        return dummy.next;
    }
};
 