class Solution {
public:
    void bfs(Node* root){
        if(!root)
            return;
        bfs(root->left);
        bfs(root->right);
        root->next = NULL;
    }
    Node* connect(Node* root) {
        bfs(root);
        return root;
    }
};