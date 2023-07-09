class Solution {
public:
    void dfs(vector<vector<int>>& v, int sr, int sc, int color, int rs, int cs, int source){
        if(sr<0 || sc<0 || sr==rs || sc==cs)
            return;
        else if(v[sr][sc] != source)
            return;
        
        v[sr][sc] = color;
        
        dfs(v, sr-1, sc, color, rs, cs, source);        //TOP
        dfs(v, sr+1, sc, color, rs, cs, source);        //DOWN
        dfs(v, sr, sc-1, color, rs, cs, source);        //LEFT
        dfs(v, sr, sc+1, color, rs, cs, source);        //RIGHT
    }
    vector<vector<int>> floodFill(vector<vector<int>>& v, int sr, int sc, int color){
        if(v[sr][sc] == color)
            return v;
        int rs = v.size();        
        int cs = v[0].size();
        int source = v[sr][sc];
        dfs(v, sr, sc, color, rs, cs, source);
        return v;
    }
};