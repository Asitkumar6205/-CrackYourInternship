class Solution{
    bool solve(int s, int *a, int n, int sum, int k, vector<int> &vis){
        if(!k)
            return true; 
        for(int i=0;i<n;i++){
            if(vis[i])
                continue;  
            if(s+a[i]==sum) {  
                vis[i]=1;     
                if(solve(0, a, n, sum, k-1, vis))return true; 
                vis[i]=0;   
            }
            else if(s + a[i] < sum){ 
                vis[i]=1;            
                if(solve(s + a[i], a, n, sum, k, vis))return true; 
                vis[i]=0;  
            }
        }
        return false;  
    }
    public:
    bool isKPartitionPossible(int a[], int n, int k){
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=a[i];
        vector<int> arr(n);             
        if(sum%k)return false;  
        else return solve(0, a, n, sum/k, k, arr);
    }
};