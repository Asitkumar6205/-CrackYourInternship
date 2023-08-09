int celebrity(vector<vector<int> >& M, int n) {
    vector<int>indegree(n,0);
    vector<int>outdegree(n,0);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(M[i][j] == 1) {
                indegree[j]++;
                outdegree[i]++;
            }
        }
    }
    for(int i=0;i<n;i++)
        if(indegree[i] == n-1 && outdegree[i] == 0) 
            return i;
    return -1;
}