class Solution{
    public:
    Node* segregate(Node *head) {
        int count[3]={0};
        Node *temp=head;
        while(temp){
            count[temp->data]++;
            temp=temp->next;
        }
        temp=head;
        int i=0;
        while(temp){
            if(count[i]==0){
                i++;
            }
            else{
                temp->data=i;
                count[i]--;
                temp=temp->next;
            }
        }
        return head;
    }
};