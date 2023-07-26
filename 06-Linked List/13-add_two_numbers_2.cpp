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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        int c = 0;
        while(l1!=NULL || l2!=NULL || c){
            int sum = 0;
            if(l1!=NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL){
                sum += l2->val;
                l2 = l2->next;
            }  
            sum += c;
            c = sum/10;
            ListNode* node = new ListNode(sum%10);
            temp->next = node;
            temp = temp->next;
        }
        ListNode* ans = dummy->next;  
        ans = reverseList(ans);
        return ans; 
    }
};