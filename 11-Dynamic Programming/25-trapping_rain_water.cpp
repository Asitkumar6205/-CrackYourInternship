class Solution {
public:
    int trap(vector<int>&v){
        int s=v.size();
        int lmax[s],rmax[s];
        long long int sum=0;
      
        lmax[0]=v[0];
        for(int i=1;i<s;i++)
            lmax[i]=max(lmax[i-1],v[i]);

        rmax[s-1]=v[s-1];
        for(int i=s-2;i>=0;i--)
            rmax[i]=max(rmax[i+1],v[i]);
          
        for(int i=1;i<s-1;i++)
            sum+=min(lmax[i],rmax[i])-v[i];
        
        return s>2?sum:0;
    }
};