class Solution {
public:
    
    int length(ListNode* head){
        int l=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            l++;
        }
        return l;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k, int l){
        if(l<k){
            return head;
        }
        
        ListNode* prevptr=NULL;
        ListNode* currptr=head;
        ListNode* nextptr;
        int c=0;
        while(currptr!=NULL && c<k){
            nextptr=currptr->next;
            currptr->next=prevptr;
            prevptr=currptr;
            currptr=nextptr;
            c++;
        }
            
        if(nextptr!=NULL){
            head->next=reverseKGroup(nextptr,k,l-k);
        }
            
        return prevptr;
    }
        
    ListNode* reverseKGroup(ListNode* head,int k){
        int l = length(head);
        return reverseKGroup(head,k,l);
    }
};