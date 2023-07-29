int maxLen(vector<int>&A, int n){   
    unordered_map<int,int> m;
    int ans=0;
    int sum=0;
    m[0]=-1;
    for(int i=0;i<n;i++){
        sum+=A[i];
        if(m.find(sum)!=m.end())
            ans=max(ans,i-m[sum]);
        else
        m[sum]=i;
    }
    return ans;
}