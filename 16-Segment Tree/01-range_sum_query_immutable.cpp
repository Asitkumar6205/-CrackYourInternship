class NumArray {
public:
vector<int>a;
    NumArray(vector<int>& nums) {
        a.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        a.push_back(nums[i]+a[i-1]);
    }
    
    int sumRange(int left, int right) {
        if(left==0 )
        return a[right];
        
        return a[right]-a[left-1];
    }
};