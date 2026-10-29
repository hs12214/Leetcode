/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head,int x) {
    struct ListNode small,big;
    struct ListNode *s=&small,*b=&big;
    while(head) {
        if(head->val<x) {
            s->next=head;
            s=s->next;
        } else {
            b->next=head;
            b=b->next;
        }
        head=head->next;
    }
    b->next=NULL;
    s->next=big.next;
    return small.next;
}