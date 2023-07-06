class Solution {
  public:
    void dfs(vector<vector<char>>& grid, int i, int j, int rs, int cs){
        if(i<0 || j<0 || i==rs || j==cs || grid[i][j]!='1')
            return;
            
        grid[i][j] = '2';
        
        dfs(grid, i-1, j, rs, cs);   //TOP
        dfs(grid, i+1, j, rs, cs);   //DOWN
        dfs(grid, i, j-1, rs, cs);   //LEFT
        dfs(grid, i, j+1, rs, cs);   //RIGHT
        
        dfs(grid, i-1, j-1, rs, cs); //DIAGONALS
        dfs(grid, i+1, j+1, rs, cs); //   |
        dfs(grid, i-1, j+1, rs, cs); //   |
        dfs(grid, i+1, j-1, rs, cs); //   V
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid){
        int rs = grid.size();
        int cs = grid[0].size();
        int islands = 0;
        for(int i=0;i<rs;i++){
            for(int j=0;j<cs;j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j, rs, cs);
                    islands += 1;
                }
            }
        }
        return islands;
    }
};