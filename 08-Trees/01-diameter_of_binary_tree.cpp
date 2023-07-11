class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL)
            return 0;
        return 1+max(height(root->left),height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        int o1=height(root->left)+height(root->right);
        int o2=max(diameterOfBinaryTree(root->left),
                   diameterOfBinaryTree(root->right));
        return max(o1,o2);
    }
};