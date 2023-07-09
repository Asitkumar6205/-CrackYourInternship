class Solution{
    public:
    void solve(vector<string>&v,string str,vector<vector<int>> &m, int n,int row,int col){
        if(row<0 || col<0 || row==n || col==n || m[row][col]==0)
            return;
        if(row==n-1 && col==n-1){
            v.push_back(str);
            return;
        }
        m[row][col]=0;
        solve(v,str+'D',m,n,row+1,col);
        solve(v,str+'U',m,n,row-1,col);
        solve(v,str+'L',m,n,row,col-1);
        solve(v,str+'R',m,n,row,col+1);
        m[row][col]=1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> v;
        solve(v,"",m,n,0,0);
        return v;
    }
};