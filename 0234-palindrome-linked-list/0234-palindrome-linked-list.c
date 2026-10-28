/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode *slow=head,*fast=head;
    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    struct ListNode *prev=NULL,*nextNode;

    while(slow){
        nextNode=slow->next;
        slow->next=prev;
        prev=slow;
        slow=nextNode;
    }

    while(prev){
        if(head->val!=prev->val)
            return false;
        head=head->next;
        prev=prev->next;
    }
    return true;
}