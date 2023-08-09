class Solution{
public:
    void path(vector<vector<int>>& ans,vector<int> vect,Node *root, int sum){
        if(root==NULL || sum<0)  
             return ;
        vect.push_back(root->key);
        if(sum-root->key==0){
            ans.push_back(vect);
            return;
        } 
        path(ans,vect,root->left,sum-(root->key));
        path(ans,vect,root->right,sum-(root->key));
    }
    vector<vector<int>> printPaths(Node *root, int sum){
        vector<vector<int>>ans;
        vector<int>vect;
        path(ans,vect,root,sum);
        return ans;
    }
};