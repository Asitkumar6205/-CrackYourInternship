class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* left=dummy;
        ListNode* right=dummy;
        if(head==NULL){
            return NULL;
        }
        while(n--){
            right=right->next;
        }
        while(right->next!=NULL){
            left=left->next;
            right=right->next;
        }
        left->next=left->next->next;
        return dummy->next;
    }
};