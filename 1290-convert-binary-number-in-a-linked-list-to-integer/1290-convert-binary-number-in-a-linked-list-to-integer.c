/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getDecimalValue(struct ListNode* head) {
    int value=0;
    for(struct ListNode*cur=head;cur!=NULL;cur=cur->next){
        value=value*2 + cur->val;
    }
    return value;
}