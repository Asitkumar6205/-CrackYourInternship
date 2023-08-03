class Solution {
public:
    int ans = -1, c=0;
    void reverse_inorder_traversal(TreeNode* root){
        if(root == NULL)
            return;
        reverse_inorder_traversal(root->left);
        c--;    
        if(c == 0){
            ans = root->val;
            return;
        }            
        reverse_inorder_traversal(root->right);
    }
    int kthSmallest(TreeNode* root, int k){
        c = k;
        reverse_inorder_traversal(root);
        return ans;
    }
};