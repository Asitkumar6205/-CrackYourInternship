void help(Node* newRoot, int a, int b, int d, int &res){
    if(newRoot==NULL)
        return;
    if(newRoot->data==a)
        res=res+d;
    if(newRoot->data==b)
        res=res+d;
    help(newRoot->left,a,b,d+1,res);
    help(newRoot->right,a,b,d+1,res);
}
    
    
Node* lca(Node* root,int n1,int n2){
    if(root==NULL)
        return NULL;
    if(root->data==n1 || root->data==n2)
        return root; 
    Node* a=lca(root->left,n1,n2);
    Node* b=lca(root->right,n1,n2); 
    if(a!=NULL && b!=NULL)
        return root;
    if(a!=NULL)
        return a;
    else
        return b;
}
    
int findDist(Node* root, int a, int b) {
    Node * newRoot=lca(root,a,b);
    int res=0;
    help(newRoot,a,b,0,res);
    return res;
}