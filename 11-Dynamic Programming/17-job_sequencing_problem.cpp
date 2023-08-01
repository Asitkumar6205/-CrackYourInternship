class Solution {
    public:
    vector<int> JobScheduling(Job arr[], int N) { 
        vector<vector<int>>v(N);
        priority_queue<int>pq;
        vector<int>ans(2,0);
        for(int i =0;i<N;i++)
            v[arr[i].dead-1].push_back(arr[i].profit);
        for(int i=N-1;i>=0;i--){
            for(int j=0;j<v[i].size();j++)
                pq.push(v[i][j]);
            if(!pq.empty()){
                ans[0]++;
                ans[1] += pq.top();
                pq.pop();
            }
        }
        return ans;
    } 
};