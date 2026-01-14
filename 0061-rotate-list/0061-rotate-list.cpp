class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int n = 0;
        ListNode* tail = head;

        while (tail) {
            n++;
            if (!tail->next) break;
            tail = tail->next;
        }

        k %= n;
        if (k == 0) return head;

        ListNode* newTail = head;
        for (int i = 1; i < n - k; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = NULL;
        tail->next = head;

        return newHead;
    }
};
