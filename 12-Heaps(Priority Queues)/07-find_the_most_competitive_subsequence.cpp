class Solution {
public:
    vector<int> mostCompetitive(vector<int>& A, int k) {
        int n=A.size();
        k=n-k;
        vector<int>ans;
        for(int i=0;i<n;i++){
            while(ans.size() and ans.back()>A[i] and k>0)  //We have the power to pop until k>0 
                ans.pop_back(),k--;
            ans.push_back(A[i]);
        }
        while(k>0 and ans.size())  //If some elements were not able to pop by the loop
            ans.pop_back(),k--;
        return ans;
    }
};