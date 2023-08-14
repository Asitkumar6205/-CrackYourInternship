class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> minheap;
        vector<vector<int>> vis(n,vector<int>(n,0));
        vector<int> dx={0,-1,0,1};
        vector<int> dy={-1,0,1,0};
        minheap.push({grid[0][0],{0,0}});
        vis[0][0]=1;
        while(!minheap.empty()){
            int t=minheap.top().first;
            int x=minheap.top().second.first;
            int y=minheap.top().second.second;
            minheap.pop();
            if(x==n-1 && y==n-1) 
                return t;
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<n && nx>=0 && ny<n && ny>=0 && vis[nx][ny]!=1){
                    vis[nx][ny]=1;
                    if(grid[nx][ny]<=t)
                        minheap.push({t,{nx,ny}}); //No need to update time
                    else
                        minheap.push({grid[nx][ny],{nx,ny}}); //Update time
                }
            }
        }
        return 0;
    }
};