class Solution {
public:
    void inorder(TreeNode* root,TreeNode* & prev, bool &f){
        if(!root) return;
        inorder(root->left,prev,f);
        if(prev != NULL && prev->val >= root->val){
            f = false;
            return;
        }
        prev = root;
        inorder(root->right,prev,f);
    }
    bool isValidBST(TreeNode* root) {
        bool f = true;
        TreeNode* prev = NULL;
        inorder(root,prev,f);
        return f;
    }
};