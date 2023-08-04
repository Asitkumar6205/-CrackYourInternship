Node *flatten(Node *root){
    Node* n = root;
    Node* b = root;
    vector<int> v;
    
    while(n){
        v.push_back(n->data);
        b = n->bottom;
        while(b){
            v.push_back(b->data);
            b = b->bottom;
        }
        n = n->next;
    }
    
    sort(v.begin(), v.end());

    Node* t = new Node(0);
    Node* ptr = t;
    Node* ans = t;
    
    for(int i=0; i<v.size(); i++){
        Node* temp = new Node(v[i]);
        ptr->bottom = temp;
        ptr = ptr->bottom;
    }
    
    return ans->bottom;
}