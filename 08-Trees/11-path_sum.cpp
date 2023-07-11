class Solution {
public:
    bool isLeaf(TreeNode* root){
        if(!root->left and !root->right)return true;
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)return false;
        targetSum-=root->val;
        if(targetSum==0 and isLeaf(root))return true;
        return hasPathSum(root->left,targetSum)|| hasPathSum(root->right,targetSum);
    }
};