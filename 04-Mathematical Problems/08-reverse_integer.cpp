class Solution {
public:
    void dfs(int node, int vis[], vector<vector<int>> adj, int count){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it])
                dfs(it, vis, adj, ans);
        }
    }

    int beauty(int n, int m, string s, int x[], int y[]) {
        vector<vector<char> adj(n);
        vector<pair<int,int>> edges(m);
        
        for(int i=0; i<m; i++)
            edges.push_back({x[i],y[i]});

        for(auto it : edges)
            adj[s[it.first]].push_back(s[it.second]);

        vector<pair<int,char>> mp;

        int vis[n] = {0};
        
        for(int i=0; i<n; i++){
            int count = 0;

            dfs(0, vis, adj, count);
        }

    }
};