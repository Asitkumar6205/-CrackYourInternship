class Solution{
	public:
    void toposort_dfs(int node, vector<int> adj[], vector<int>& vis, stack<int>& s){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it])
                toposort_dfs(it,adj,vis,s);
        }
	    s.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) {
	    stack<int> s;
	    vector<int> vis(V,0);
	    for(int i=0;i<V;i++){
	        if(vis[i]==0)
	            toposort_dfs(i,adj,vis,s);
	    }
	    vector<int> topo;
	    while(!s.empty()){
	        topo.push_back(s.top());
	        s.pop();
	    }
	    return topo;
	}
};