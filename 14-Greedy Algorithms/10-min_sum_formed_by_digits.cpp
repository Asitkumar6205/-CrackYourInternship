long long int minSum(int arr[], int n){
    long long int n1=0,n2=0,res=0;
    sort(arr,arr+n);
    int flag =0;
    for(int i=0;i<n;i++){
        if(flag==1){
            n1 = n1*10+arr[i];
            flag=0;
        }
        else {
            n2 = n2*10+arr[i];
            flag=1;
        }
    }
    return n1+n2;
}