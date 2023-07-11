class Solution {
public:
    TreeNode* helper(TreeNode* &root1, TreeNode* root2){
        if(!root1)
            return root2;
        if(!root2)
            return root1;
        root1->val = root1->val + root2->val;
        root1->left = helper(root1->left, root2->left);
        root1->right = helper(root1->right, root2->right);
        return root1;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return helper(root1, root2);
    }
};