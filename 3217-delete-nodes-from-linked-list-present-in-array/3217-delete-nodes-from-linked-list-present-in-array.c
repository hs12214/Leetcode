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
struct ListNode* modifiedList(int* nums,int numsSize,struct ListNode* head){
    int seen[100001]={0};

    for(int i=0;i<numsSize;i++)
        seen[nums[i]]=1;
   
    struct ListNode d;
    d.next=head;
    struct ListNode *p=&d,*c=head;
    while(c){
        if(seen[c->val])
            p->next=c->next;
        else
            p=c;
        c=c->next;
    }
    return d.next;
}