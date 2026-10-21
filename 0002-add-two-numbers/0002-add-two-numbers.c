/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode*createNode(int val){
    struct ListNode*newnode=malloc(sizeof(struct ListNode));
    newnode->val=val;
    newnode->next=NULL;
    return newnode;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode*curr=createNode(0);
    struct ListNode*dummy=curr;
    int carry=0;
    while(l1!=NULL || l2!=NULL || carry!=0){
        int sum=carry;
        if(l1!=NULL){
            sum+=l1->val;
            l1=l1->next;}
        if(l2!=NULL){
            sum+=l2->val;
            l2=l2->next;
        }
        curr->next=createNode(sum%10);
        curr=curr->next;
        carry=sum/10;
            }
        return dummy->next;
}