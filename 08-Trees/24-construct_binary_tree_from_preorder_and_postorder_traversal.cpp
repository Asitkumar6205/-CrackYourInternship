bclass Solution {
    int preindex=0,posindex=0;
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* root=new TreeNode(preorder[preindex++]);
        if(root->val!=postorder[posindex])
            root->left=constructFromPrePost(preorder,postorder);
        if(root->val!=postorder[posindex])
            root->right=constructFromPrePost(preorder,postorder);
        posindex++;
        return root;
    }
};