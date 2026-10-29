/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode *cur=head->next,*ans=head->next;
    int sum=0;
    while(cur) {
        if(cur->val==0) {
            ans->val=sum;
            ans=ans->next;
            sum=0;
        } else {
            sum+=cur->val;
        }
        cur=cur->next;
    }
    cur=head->next;
    while(cur&&cur->next!=ans)
        cur=cur->next;
    if(cur)
        cur->next=NULL;
    return head->next;
}