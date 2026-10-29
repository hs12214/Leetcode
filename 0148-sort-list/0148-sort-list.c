/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* sortList(struct ListNode* head) {
    if(!head||!head->next)
        return head;
    struct ListNode *slow=head,*fast=head->next;
    while(fast&&fast->next) {
        slow=slow->next;
        fast=fast->next->next;
    }
    struct ListNode *head2=slow->next;
    slow->next=NULL;
    head=sortList(head);
    head2=sortList(head2);
    struct ListNode dummy;
    struct ListNode *tail=&dummy;
    while(head&&head2) {
        if(head->val<head2->val) {
            tail->next=head;
            head=head->next;
        } else {
            tail->next=head2;
            head2=head2->next;
        }
        tail=tail->next;
    }
    tail->next=head?head:head2;
    return dummy.next;
}