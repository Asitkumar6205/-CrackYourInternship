class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minm = INT_MAX;
        int profit = 0;
        for(int i=0;i<prices.size();i++){
            minm = min(prices[i], minm);
            profit = max(prices[i]-minm, profit);
        }
        return profit;
    }
};