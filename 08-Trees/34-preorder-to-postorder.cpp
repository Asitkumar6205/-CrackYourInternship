class Solution{
public:
    Node* insert(Node* root,int x){
        if(root==NULL)
            return newNode(x);
        if(root->data<x)
            root->right = insert(root->right,x);
        else if(root->data > x)
            root->left = insert(root->left,x);
        return root;    
    }
    Node* post_order(int pre[], int size){
        Node * root = newNode(pre[0]);
        for(int i=1;i<size;i++)
            insert(root,pre[i]);
        return root;    
    }
};