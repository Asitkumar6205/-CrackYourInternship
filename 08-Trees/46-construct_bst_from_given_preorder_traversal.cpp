struct Node* solution(int n , int pre[] , char preLN[] , int &i){
    if(i >= n) return NULL;
    struct Node* root = new struct Node(pre[i]);
    if(preLN[i++] == 'L'){
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    root->left = solution(n , pre , preLN , i);
    root->right = solution(n , pre , preLN , i);
    return root;
}
struct Node *constructTree(int n, int pre[], char preLN[]){
    int i = 0;
    return solution(n , pre , preLN , i);
}

