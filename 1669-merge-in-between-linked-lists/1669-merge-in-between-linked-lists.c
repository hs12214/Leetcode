/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeInBetween(struct ListNode* list1,int a,int b,struct ListNode* list2) {
    struct ListNode *left=list1,*right=list1;
    for(int i=0;i<a-1;i++)
        left=left->next;
    for(int i=0;i<=b;i++)
        right=right->next;
    left->next=list2;
    while(list2->next)
        list2=list2->next;
    list2->next=right;
    return list1;
}