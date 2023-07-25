class Solution{
public:
    int largestRectangleArea(vector<int> &heights){
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<pair<int, int>> st;

        for (int i = n - 1; i >= 0; i--){
            while (!st.empty() && st.top().first >= heights[i]) st.pop();
            if (st.empty())  right[i] = n - 1;
            else right[i] = st.top().second - 1;
            st.push({heights[i], i});
        }

        st = {};

        for (int i = 0; i < n; i++){
            while (!st.empty() && st.top().first >= heights[i])st.pop();
            if (st.empty()) left[i] = 0;
            else left[i] = st.top().second + 1;
            st.push({heights[i], i});
        }
        
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) maxi = max(heights[i] * (right[i] - left[i] + 1), maxi);
        
        return maxi;
    }
};