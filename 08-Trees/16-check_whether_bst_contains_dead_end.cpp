bool solve(Node* root, int mini, int maxi){
    if(root==NULL) 
        return false;
    if(mini==maxi)
        return true;
    if(solve(root->left, mini, root->data-1))
        return true;
    if(solve(root->right, root->data+1, maxi))
        return true;
    return false;
}
bool isDeadEnd(Node *root){
    return solve(root,1,INT_MAX);
}