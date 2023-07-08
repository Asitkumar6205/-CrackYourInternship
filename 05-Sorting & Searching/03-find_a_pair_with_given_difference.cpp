bool findPair(int arr[], int size, int n){
    unordered_map<int,int> m; 
    for(int i=0;i<size;i++)
        m[arr[i]]=i+1;
    for(int i=0;i<size;i++)
        if(abs(m[abs(n-arr[i])])!=i+1 && m[abs(n-arr[i])]!=0)return true;
    return false;
}