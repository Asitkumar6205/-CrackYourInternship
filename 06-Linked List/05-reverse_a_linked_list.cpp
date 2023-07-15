class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prevptr=NULL;
        ListNode* currptr=head;
        ListNode* nextptr;
        while(currptr!=NULL){
            nextptr=currptr->next;
            currptr->next=prevptr;
            prevptr=currptr;
            currptr=nextptr;
        }
    return prevptr;    
    }
};