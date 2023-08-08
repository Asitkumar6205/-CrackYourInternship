class Solution{
public:
    int isNegativeWeightCycle(int V, vector<vector<int>>edges){
	    vector<int> dist(V, 1e8);
        dist[0]=0;
        
        for(int i=0;i<V-1;i++){
            for(auto edge : edges){
                int u = edge[0], v=edge[1], wt = edge[2];
                if(dist[u]+wt < dist[v])
                    dist[v]=dist[u]+wt;
            }
        }
        
        for(auto edge : edges){
            int u = edge[0], v=edge[1], wt = edge[2];
            if(dist[u]+wt < dist[v]) return 1;
        }
        
        return 0;
	}
};