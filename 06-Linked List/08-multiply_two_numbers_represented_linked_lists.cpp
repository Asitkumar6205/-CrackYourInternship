long long  multiplyTwoLists (Node* l1, Node* l2){
        int mod =1e9+7;
        long long int n=0;
        while(l1!=NULL){
           n=(n*10+ l1->data)%mod;
           l1=l1->next;
        }
        long long int n2=0;
        while(l2!=NULL){
           n2=(n2*10 + l2->data)%mod;
           l2=l2->next;
        }
        
        return (n*n2)%mod;
        
}

