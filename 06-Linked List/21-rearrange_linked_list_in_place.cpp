class Solution {
public:
    void reorderList(ListNode* head) {
        
        ListNode*tra=head;

        while(tra->next!=NULL && tra->next->next!=NULL){
            ListNode*p=tra;
            while(p->next->next!=NULL){
                p=p->next;
        }

        p->next->next=tra->next;
        tra->next=p->next;
        p->next=NULL;
        tra=tra->next->next;
        }
    }
};