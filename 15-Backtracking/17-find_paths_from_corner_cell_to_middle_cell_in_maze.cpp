void printPath(vector<vector<int>>&maze, int i, int j, string ans){
    if (i == maze.size()/2 && j==maze.size()/2){
        ans += "(";
        ans += to_string(i);
        ans += ", ";
        ans += to_string(j);
        ans += ") -> MID";
        cout<<ans<<endl;
        return;
    }
    if (maze[i][j]==0)
        return;
    int k = maze[i][j];
    maze[i][j]=0;
    ans += "(";
    ans += to_string(i);
    ans += ", ";
    ans += to_string(j);
    ans += ") -> ";
    if(j+k<maze.size())
       printPath(maze, i, j+k, ans);
    if(i+k<maze.size())
       printPath(maze, i+k, j,ans);
    if(j-k>0)
       printPath(maze, i, j-k, ans);
    if(i-k>0)
        printPath(maze, i-k, j, ans);
    maze[i][j] = k;
}