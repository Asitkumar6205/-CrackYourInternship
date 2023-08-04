class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> q;
        int n = lists.size();
        for(int i=0; i<n; i++){
            ListNode* temp = lists[i];
            while(temp){
                q.push(temp->val);
                temp = temp->next;
            }
        }
        if(!q.size())return NULL;
        ListNode* head = new ListNode(q.top());
        q.pop();
        ListNode* temp = head;
        while(!q.empty()){
            temp->next = new ListNode(q.top());
            q.pop();
            temp = temp->next;
        }
        return head;
    }
};