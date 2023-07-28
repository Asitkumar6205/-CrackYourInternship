class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
            return  NULL;
        ListNode* dummy = new ListNode(0,head);
        ListNode* p=dummy, *q=head;
        int flag=1;
        while(q && q->next){
            if(q->val == q->next->val){
                q=q->next;
                flag=0;
            }
            else{
                if(flag){
                    p=p->next;
                    q=q->next;
                }
                else{
                    p->next = q->next;
                    q=q->next;
                }
                flag=1;
            }
        }
        if(flag){
            p=p->next;
            q=q->next;
        }
        else{
            p->next = q->next;
            q=q->next;
        }
        return dummy->next;
    }
};