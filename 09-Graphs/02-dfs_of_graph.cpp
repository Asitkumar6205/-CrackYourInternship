class Solution {
  public:
    void dfs(vector<int> &ans, vector<int> adj[], int vis[], int node){
        vis[node] = 1;
        ans.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it])
                dfs(ans, adj, vis, it);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};
        vector<int> ans;
        dfs(ans, adj, vis, 0);
        return ans;
    }
};