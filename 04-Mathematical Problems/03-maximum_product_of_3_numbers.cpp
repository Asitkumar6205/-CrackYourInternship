class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int prod1, prod2;
        sort(nums.begin(), nums.end());
        prod1 = nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3];
        prod2 = nums[nums.size()-1]*nums[0]*nums[1];
        return max(prod1, prod2);
    }
};