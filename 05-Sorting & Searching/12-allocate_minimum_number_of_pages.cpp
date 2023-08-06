class Solution {
    public:
    bool isPossibleSolution(int *a, int n, int m , int sol){
        int count=1;
        int pagesum=0;
        for(int i=0;i<n;i++){
            if(a[i]>sol)
                return false;
            if(pagesum+a[i]>sol){
                count++;
                pagesum = a[i];
                if(count>m)
                    return false;
            }
            else
                pagesum+=a[i];
        }
        return true;
    }
    int findPages(int A[], int n, int m) {
        if(m>n)
            return -1;
        int start=0;
        int sum=0;
        for(int i=0;i<n;i++)
            sum= sum+A[i];
        int end= sum;
        int ans=-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isPossibleSolution(A,n,m,mid)){
                ans= mid;
                end= mid-1;
            }
            else
                start= mid+1;
        }
        return ans;
    }
};