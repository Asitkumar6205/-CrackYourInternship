class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        int res=1;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
           int start=q.front().second;
           int end=q.back().second;
           int size=q.size();
           res=max(res,end-start+1);
           for(int i=0;i<size;i++){
               pair<TreeNode*,int>p=q.front();
               int idx=p.second-start;
               q.pop();
               if(p.first->left)q.push({p.first->left,(long long)idx*2+1});
               if(p.first->right)q.push({p.first->right,(long long )idx*2+2});
           }
            
        }
        return res;
    }
};