class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* node = s.top();
            s.pop();
            if(node){
                s.push(node->left);
                s.push(node->right);
                swap(node->left,node->right);
            }  
        }
        return root;
    }
};