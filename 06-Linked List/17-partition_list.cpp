class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lower = new ListNode();
        ListNode* ans = lower;
        ListNode* higher = new ListNode();
        ListNode* temp = higher;

        while(head){
            if(head->val < x) lower->next = new ListNode(head->val), lower = lower->next;
            else higher->next = new ListNode(head->val), higher = higher->next;
            head = head->next;
        }

        lower->next = temp->next;
        return ans->next;
    }
};