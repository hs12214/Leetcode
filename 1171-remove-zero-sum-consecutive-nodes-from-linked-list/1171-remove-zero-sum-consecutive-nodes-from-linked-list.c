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

struct ListNode* removeZeroSumSublists(struct ListNode* head){
    struct ListNode d;
    d.val=0;
    d.next=head;
    struct ListNode *start=&d;
    while(start){
        int sum=0;
        struct ListNode *end=start->next;
        while(end){
            sum+=end->val;
            if(sum==0){
                start->next=end->next;
                end=start->next;
                sum=0;
                continue;
            }
            end=end->next;
        }
        start=start->next;
    }
    return d.next;
}