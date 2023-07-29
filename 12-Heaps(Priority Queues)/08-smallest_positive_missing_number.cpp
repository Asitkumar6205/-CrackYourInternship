int missingNumber(int arr[], int n) { 
    int ans;
    unordered_map<int,int> mp;
     for(int i=0;i<n;i++)
        mp[arr[i]]++;
        for(int i=1;i<=n+1;i++){
            if(mp[i]==0){
                ans=i;
                break;
            }
        }
    }
    return ans;
} 