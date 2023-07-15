class Solution{
  public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        Node* temp=new Node(-1);
        Node* temp_head=temp;
        unordered_map<int,bool> un;
        while(head2!=NULL){
            un[head2->data]=true;
            head2=head2->next;
        }
        while(head1!=NULL){
            if(un[head1->data]){
                temp->next=head1;
                temp=temp->next;
            }
            head1=head1->next;
        }
        temp->next=NULL;
        return temp_head->next;
    }
};