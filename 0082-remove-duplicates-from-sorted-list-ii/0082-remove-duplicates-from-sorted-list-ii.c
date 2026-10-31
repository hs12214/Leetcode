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
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode d;
    d.next=head;
    struct ListNode *prev=&d,*cur=head;
    while(cur){
        if(cur->next&&cur->val==cur->next->val){
            int x=cur->val;
            while(cur&&cur->val==x)
                cur=cur->next;
            prev->next=cur;
        }else{
            prev=cur;
            cur=cur->next;
        }
    }
    return d.next;
}