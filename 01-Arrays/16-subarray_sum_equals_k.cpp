class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size=nums.size();
        int i=0, j=0, c=0, prefix_sum=0;
        unordered_map<int,int>m;
        for(int i=0;i<size;i++){
            prefix_sum+=nums[i];
            if(prefix_sum==k) c++;
            if(m.find(prefix_sum-k)!=m.end())
                c+=m[prefix_sum-k];
            
            m[prefix_sum]+=1;
        }
    return c;
    }
};