class Solution {
public:
    vector<int> rightSideView(TreeNode* root){
        vector<int>ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                if(node->right != NULL) q.push(node->right);
                if(node->left != NULL) q.push(node->left);
                temp.push_back(node->val);
                q.pop();
            }
            ans.push_back(temp[0]);
        }
        return ans;
    }
};
