 int n=nums.size();
        unordered_map<int,int>m;
        vector<int>v=nums;
        sort(v.begin(),v.end());
        int ans=0;
        for(int i=0;i<n;i++)
        {
            m[v[i]]=i;
        }
        int j=0;
        while(j<n)
        {
            if(j!=m[nums[j]])
            {
                swap(nums[j],nums[m[nums[j]]]);
                ans++;
            }
            else
            {
                j++;
            }
        }
        return ans;