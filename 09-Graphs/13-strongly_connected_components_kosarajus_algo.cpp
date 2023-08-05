class Solution{
	public:
	
	void dfs(int index  , vector<int> &vis , vector<vector<int>>& adj , stack<int>&st){
	    
	    vis[index] = 1;
	    for(auto it : adj[index]){
	        if(!vis[it]){
	            dfs(it , vis , adj , st);
	        }
	    }
	    st.push(index);
	}
	
	void dfs1(int index  , vector<int> &vis , vector<int>adj1[] ){
	    vis[index] = 1;
	    for(auto it : adj1[index]){
	        if(!vis[it]){
	            dfs1(it , vis , adj1);
	        }
	    }
	}
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        stack<int> st;
        vector<int> vis(V , 0);
        vector<int> adj1[V];
       
        
        for(int i = 0 ; i<V  ;i++){
            if(!vis[i]){
                dfs( i , vis , adj , st);
            }
        }
        
        for(int i = 0 ; i<V ; i++){
            vis[i] = 0;
            for(auto it : adj[i]){
                adj1[it].push_back(i);
            }
        }
        
        int ans = 0;
        while(!st.empty()){
            int t = st.top();
            st.pop();
            if(!vis[t]){
                dfs1(t , vis , adj1);
                ans++;
            }
        }
        return ans;
    }
};