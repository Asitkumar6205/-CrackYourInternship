class NumArray {
public:
    vector<int> temp;
    int sum=0;
    NumArray(vector<int>& nums) {
        temp=nums;
        sum=accumulate(nums.begin(),nums.end(),0);  //Sum of all Elemnts in vector
    }
    
    void update(int index, int val) {
        sum-=temp[index];
        sum+=val;
        temp[index]=val;
    }
    
    int sumRange(int left, int right) {
        int ans=sum;
        for(int i=0;i<left;i++)
            ans-=temp[i];
        for(int i=right+1;i<temp.size();i++)
            ans-=temp[i];
        return ans;
    }
};