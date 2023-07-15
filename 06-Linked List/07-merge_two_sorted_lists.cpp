class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        while(l1!=NULL && l2!=NULL){
            if(l1->val<=l2->val){
                temp->next=l1;
                temp=temp->next;
                l1=l1->next;
            }
            else{
                temp->next=l2;
                temp=temp->next;
                l2=l2->next;
            }
        }
        while(l1!=NULL){
            temp->next=l1;
            temp=temp->next;
            l1=l1->next;
        }
        while(l2!=NULL){
            temp->next=l2;
            temp=temp->next;
            l2=l2->next;
        }
    return dummy->next;
    }
};