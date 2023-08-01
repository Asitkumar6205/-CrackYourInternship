class Solution{
public:
    int deleteAndEarn(vector<int>&nums){
        int n=10001;
        vector<int>total_points(n,0);
        for(int ele:nums)
            total_points[ele]+=ele;
        int take=0, skip=0;
        for(int i=0;i<n;i++){
            int take_curr=skip+total_points[i];
            int skip_curr=max(skip,take);
            take=take_curr;
            skip=skip_curr;
        }
        return max(take,skip);
    }
};