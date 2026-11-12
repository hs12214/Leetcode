/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool isPalindrome(struct ListNode* head)
{
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode *prev = NULL;
    struct ListNode *curr = slow;
    struct ListNode *next;

    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    struct ListNode *p1 = head;
    struct ListNode *p2 = prev;

    while(p2)
    {
        if(p1->val != p2->val)
            return false;

        p1 = p1->next;
        p2 = p2->next;
    }

    return true;
}