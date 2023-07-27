class Solution{
    public:

        void findlsrs(int arr[],int n,vector<int>&ls,vector<int>&rs){
        stack<int>l,r;
        for(int i=0;i<n;i++){
            while(!l.empty() && arr[l.top()]>=arr[i])l.pop();
            while(!r.empty() && arr[r.top()]>=arr[n-i-1])r.pop();
            
            if(!l.empty())ls[i]=l.top();
            if(!r.empty())rs[n-i-1]=r.top();
            
            l.push(i);
            r.push(n-i-1);
        }
    }
    vector <int> maxOfMin(int arr[], int n){
        vector<int>ls(n,-1),rs(n,n),ans(n,-1);
        findlsrs(arr,n,ls,rs);
        for(int i=0;i<n;i++){
           int ind=rs[i]-ls[i]-2;
           ans[ind]=max(ans[ind],arr[i]);
        }
        for(int i=n-2;i>=0;i--){
            ans[i]=max(ans[i],ans[i+1]);
        }
        return ans;
    }
};