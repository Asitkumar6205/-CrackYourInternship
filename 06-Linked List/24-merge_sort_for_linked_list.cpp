Node* getmid(Node* head) {
    if (head == NULL || head->next == NULL) 
        return head;

    Node* slow = head;
    Node* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
    
    
Node* merge(Node* head1, Node* head2){  

    if(!head1) return head2;
    if(!head2) return head1;
    
    if(head1->data <= head2->data){
        head1->next=merge(head1->next,head2);
        return head1;
    }
    else{
        head2->next=merge(head2->next,head1);
        return head2;
    }
}  

Node* mergeSort(Node* head) {
    if (head == NULL || head->next == NULL) 
        return head;

    Node* mid = getmid(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    Node* result = merge(left, right);
    return result;
}