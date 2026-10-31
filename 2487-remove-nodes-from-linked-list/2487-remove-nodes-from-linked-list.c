/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* rev(struct ListNode* head){
    struct ListNode *prev=NULL,*cur=head;
    while(cur){
        struct ListNode *next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    return prev;
}

struct ListNode* removeNodes(struct ListNode* head){
    head=rev(head);
    int mx=head->val;
    struct ListNode *cur=head;
    while(cur&&cur->next){
        if(cur->next->val<mx)
            cur->next=cur->next->next;
        else{
            cur=cur->next;
            mx=cur->val;
        }
    }
    return rev(head);
}