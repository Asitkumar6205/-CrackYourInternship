Node* reverseLL(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* temp = NULL;
    while(curr){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

int length(Node* head){
    if(head == NULL)
    return 0;
    int count = 1;
    while(head){
        count++;
        head = head->next;
    }
    return count;
}

void insertAtHead(Node*& head,int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

Node* subLinkedList(Node* l1, Node* l2){
    while(l1 && l1->data == 0)
        l1 = l1->next;
    while(l2 && l2->data == 0)
        l2 = l2->next;
    if(length(l1) < length(l2))
        swap(l1,l2);
    else if(length(l1) == length(l2)){
        if(l1->data < l2->data)
            swap(l1,l2);
    }
    l1 = reverseLL(l1);
    l2 = reverseLL(l2);
    int borrow = 0;
    Node* ans = NULL;
    while(l2 && l1){
        int difference = l1->data - l2->data - borrow;
        if(difference < 0){
            borrow = 1;
            difference = 10 + difference;
        }
        else
            borrow = 0;
        insertAtHead(ans,difference);
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1){
        int difference = l1->data - borrow;
        if(difference < 0){
            borrow = 1;
            difference = 10 + difference;
        }
        else
            borrow = 0;
        insertAtHead(ans,difference);
        l1 = l1->next;
    }
    while(ans && ans->data == 0)
        ans = ans->next;
    if(!ans)
        insertAtHead(ans,0);
    return ans;
}