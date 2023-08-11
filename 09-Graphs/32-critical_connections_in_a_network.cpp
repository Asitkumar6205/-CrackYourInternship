class Solution {
private:

void dfs(int node, int parent ,int& timer, vector<bool>&visited, vector<int>&disc, vector<int>&low ,vector<vector<int>>&res ,vector<vector<int>>&adj ){

    visited[node] = true;

    low[node] = disc[node] = timer++;

    for(auto neigh : adj[node]){

        if(neigh == parent)
            continue;

        if(!visited[neigh])
        {
           dfs(neigh , node , timer , visited , disc , low , res ,adj);
           low[node] = min(low[node] ,low[neigh]);

           if(low[neigh] > disc[node]){
               vector<int>ans;
                ans.push_back(node);
                ans.push_back(neigh);
                res.push_back(ans);
           }
        }
        else {

            low[node] = min(low[node] , disc[neigh]);
        }

    }

}

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        
        vector<vector<int>> adj(n);

        for(int i = 0 ; i < con.size() ; i++ ){
            int u = con[i][0];
            int v = con[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int timer =0;
        int parent=-1;

        vector<bool>visited(n , 0);
        vector<int> disc(n ,-1);
        vector<int> low(n , -1);
        vector<vector<int>>res;

        for(int i = 0 ; i < n ; i++){
            if(!visited[i])
                dfs(i , parent ,timer , visited , disc , low , res ,adj);

        }
        return res;
    }
};