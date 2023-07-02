class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(), a.end());
        long long j = m-1;
        long long min_diff = LONG_MAX;
        for(long long i=0; i<=n-m; i++)
            min_diff = min(min_diff, a[j++]-a[i]);
        return min_diff;
    }   
};