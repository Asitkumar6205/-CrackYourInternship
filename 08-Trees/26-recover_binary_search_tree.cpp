class Solution {
public:
    void inorder(TreeNode* &root,TreeNode* & prev){
        if(!root) return;
        inorder(root->left,prev);
        if(prev != NULL && prev->val >= root->val)
            swap(root,prev);
        prev = root;
        inorder(root->right,prev);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* prev = NULL;
        inorder(root,prev);
    }
};