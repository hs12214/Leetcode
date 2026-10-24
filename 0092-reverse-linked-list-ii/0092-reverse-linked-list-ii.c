/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (!head || left == right) {
        return head;
    }
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;

    struct ListNode* before = &dummy;
    for (int i = 1; i < left; i++) {
        before = before->next;
    }

    struct ListNode* first = before->next;
    for (int i = 0; i < right - left; i++) {
        struct ListNode* moved = first->next;
        first->next = moved->next;
        moved->next = before->next;
        before->next = moved;
    }
    return dummy.next;
}