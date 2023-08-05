class Solution {
public:
    int dfs(int n,vector<pair<int,int>>adj[],vector<bool>&vis,vector<int>& informTime){
        int ans=0;
        for(auto i:adj[n])
            ans=max(ans,informTime[n]+dfs(i.first,adj,vis,informTime));
        return ans;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<n;i++){   
            if(manager[i]!=-1)
                adj[manager[i]].push_back({i,informTime[i]});
        }
        vector<bool>vis(n,0);
        int ans=dfs(headID,adj,vis,informTime);
        return ans;
    }
};