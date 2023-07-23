void radixSort(int arr[], int n) { 
    int t = log10(*max_element(arr,arr+n))+1;
    for(int i = 0;i < t;i++){
        vector <queue<int>> v(10);
        for(int j = 0;j < n;j++)
            v[int(arr[j]/pow(10,i))%10].push(arr[j]);
        for(int x = 0,j = 0 ;j < 10;j++){
            while(v[j].size()){
                arr[x++] = v[j].front();
                v[j].pop();
            }
        }
    }
} 