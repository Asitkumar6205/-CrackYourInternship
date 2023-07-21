class Solution {
    void countings(vector<long>&sum,int l,int mid,int r,int &count,int lower,int upper){
        int forlessthanlower=mid+1,forlessthanequalupper=mid+1;
        for(int i=l;i<=mid;i++){
            while(forlessthanlower<=r && sum[forlessthanlower]-sum[i]<lower) forlessthanlower++;
            while(forlessthanequalupper<=r && sum[forlessthanequalupper]-sum[i]<=upper)
            forlessthanequalupper++;

            count+=forlessthanequalupper-forlessthanlower;
        }
    }
    void merge(vector<long>&sum,int l,int mid,int r,int &count,int lower,int upper){
        int left=l,right=mid+1,k=0;
        vector<long> temp(r-l+1);
        while(left<=mid && right<=r){
            if(sum[left]<=sum[right]) temp[k++]=sum[left++];
            else temp[k++]=sum[right++];
        }
        while(left<=mid) temp[k++]=sum[left++];
        while(right<=r)  temp[k++]=sum[right++];
        for(int i=l;i<=r;i++){
            sum[i]=temp[i-l];
        }
    }
    void mergesort(vector<long> &sum,int l,int r,int &count,int lower,int upper){
        if(l>=r) return;
        int  mid=l-(l-r)/2;
        mergesort(sum,l,mid,count,lower,upper);
        mergesort(sum,mid+1,r,count,lower,upper);
        countings(sum,l,mid,r,count,lower,upper);
        merge(sum,l,mid,r,count,lower,upper);
         
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long> sum(nums.size()+1,0);
        for(int i=0;i<nums.size();i++) sum[i+1]=sum[i]+nums[i];
        int count=0;
        mergesort(sum,0,nums.size(),count,lower,upper);
        return count;
    }
};