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
struct ListNode* removeElements(struct ListNode* head,int val){
    struct ListNode dummy;
    dummy.next=head;

    struct ListNode *prev=&dummy;
    struct ListNode *cur=head;
    while(cur){
        if(cur->val==val){
            prev->next=cur->next;
        }else{
            prev=cur;
        }
        cur=cur->next;
    }
    return dummy.next;
}