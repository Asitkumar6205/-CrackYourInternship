class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        TreeNode* temp=root->right;
        root->right=root->left;
        root->left=NULL;
        TreeNode* rightMost=root;
        while(rightMost->right){
            rightMost=rightMost->right;
        }
        rightMost->right=temp;
        root=root->right;
        flatten(root);
    }
};