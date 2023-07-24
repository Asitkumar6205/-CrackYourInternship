class Solution {
public:
    vector<vector<int>>nearest(vector<vector<int>>grid){
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>>ans(n, vector<int>(m, 0)), vis(n, vector<int>(m, 0));
	    queue<pair<pair<int, int>, int>>q;
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            if(grid[i][j]){
	                q.push({{i, j}, 0});
	                vis[i][j]=1;
	            }
	        }
	    }
	    while(!q.empty()){
	        int r=q.front().first.first;
	        int c=q.front().first.second;
	        int dist=q.front().second;
	        ans[r][c]=dist;
	        q.pop();
	        
	        int delrow[]={-1, 0, 1, 0};
	        int delcol[]={0, 1, 0, -1};
	        for(int i=0; i<4; i++){
	            int nrow=r+delrow[i];
	            int ncol=c+delcol[i];
	            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=1){
	                vis[nrow][ncol]=1;
	                q.push({{nrow, ncol}, dist+1});
	            }
	        }
	    }
	    return ans;
	}
};