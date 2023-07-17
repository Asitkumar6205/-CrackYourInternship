class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pref =1, suff =1;
        int n = nums.size()-1;
        int m = INT_MIN;
        for(int i=0;i<=n;i++){
            if(pref==0)pref=1;
            if(suff==0)suff=1;
            pref *= nums[i];
            suff *= nums[n-i];
            m = max(m, max(pref,suff));
        }
        return m;
    }
};