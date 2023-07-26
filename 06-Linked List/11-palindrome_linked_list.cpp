class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        if (fast != NULL && fast -> next == NULL) slow = slow -> next;
        ListNode* prv = NULL;
        ListNode* tmp = NULL;
        while (slow != NULL) {
            tmp = slow -> next;
            slow -> next = prv;
            prv = slow;
            slow = tmp;
        }
        slow = prv, fast = head;
        while (slow && fast) {
            if (slow -> val != fast -> val) return false;
            slow = slow -> next;
            fast = fast -> next;
        }
        return true;
    }
};