class DisjointSet{
    public: 
    
    vector<int>par;
    vector<int>size;

    DisjointSet(int n){
        par.resize(n+1);
        size.resize(n+1,1);

        for(int i=0;i<=n;i++){
            par[i] = i;
        }
    }

    int findpar(int u){
        if(u == par[u]){
            return u;
        }

        return par[u] = findpar(par[u]);
    }

    void unionbysz(int u,int v){
        u = findpar(u);
        v = findpar(v);

        if(u == v) return;

        if(size[u] < size[v]){
            par[u] = v;
            size[v] += size[u];
        }
        else{
            par[v] = u;
            size[u] += size[v]; 
        }
    }
};

class Solution {
public:

bool isValid(int i,int j,int n){
    if(i<0 || i>=n || j<0 || j>=n){
        return false;
    }

    return true;
}
    vector<int>dx = {-1,0,1,0};
    vector<int>dy = {0,-1,0,1};

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        DisjointSet ds(n*n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j] == 0) continue;

                for(int idx=0;idx<4;idx++){
                    int newr = i + dx[idx];
                    int newc = j + dy[idx];

                    if(isValid(newr,newc,n) && grid[newr][newc] == 1){
                        int node = i*n + j;
                        int adjnode = newr*n + newc;

                        ds.unionbysz(node,adjnode);
                    }
                }
            }
        }

        int mx = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j] == 1) continue;

                set<int>set;

                for(int idx=0;idx<4;idx++){
                    int newr = i + dx[idx];
                    int newc = j + dy[idx];

                    if(isValid(newr,newc,n) && grid[newr][newc] == 1){
                        set.insert(ds.findpar(newr*n + newc));
                    }
                }

                int totalsize = 0;

                for(auto it: set){
                    totalsize += ds.size[it];
                }
                mx = max(mx,totalsize + 1);
            }
        }

        mx=max(mx,ds.size[ds.findpar(n*n-1)]);
        return mx;
    }
};