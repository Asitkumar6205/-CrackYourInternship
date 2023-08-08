bool isBipartite(int V, vector<int>adj[]){
    vector<int>color(V,-1);
    queue<int>q;
    for(int i=0;i<V;i++){
        if(color[i]==-1){
            q.push(i);
            color[i] = 0;
            while(!q.empty()){
                int s = q.front();
                q.pop();
                for(auto it : adj[s]){
                    if(color[it]==-1){
                        color[it] = !color[s];
                        q.push(it);
                    }
                    else if(color[it]==color[s]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}