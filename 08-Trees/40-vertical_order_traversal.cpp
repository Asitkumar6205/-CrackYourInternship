class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int, map<int,vector<int> > > nodes;   // create map to store horizonatal distance as key and map where level is key value is list of node at specific level
        queue< pair<TreeNode*, pair<int,int> > > q; // create queue for storing node inform of hd its level and node
        vector<vector<int>> v;
        
        if(root == NULL)
            return v;
            
        q.push(make_pair(root, make_pair(0,0))); // push root node where hd is 0 and level also 0
        
        while(!q.empty()) {
            pair<TreeNode*, pair<int,int> > temp = q.front();  // fetch first node from queue
            q.pop();
            TreeNode* frontNode = temp.first; // storing first treenode
            int hd = temp.second.first; // tree node hosrizontal distance
            int lvl = temp.second.second; // tree node level
            
            nodes[hd][lvl].push_back(frontNode->val); // push in map
            
            if(frontNode->left)
                q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1) )); // if left side decrrease hd to -1
                
            if(frontNode->right)
                q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1))); // if right side increase hd to + 1
            sort(nodes[hd][lvl].begin(),nodes[hd][lvl].end());  // if we have more than 1 element for same key we have to sort 
        }
        
        // storing our ans
         for(auto e:nodes){
            vector<int> res;
            for(auto i:e.second){
                for(auto j:i.second){
                   res.push_back(j);
                }
            } 
            v.push_back(res);
        }
        return v;
        
    }
};