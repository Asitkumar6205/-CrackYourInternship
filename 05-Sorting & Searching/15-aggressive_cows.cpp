class Solution {
public:
    bool canWePlace(vector<int>& stalls, int dis, int cows){
    int cntcows = 1;
    int last = stalls[0];
    for(int i=1 ; i<stalls.size(); i++){
        if(stalls[i]-last>=dis){
          cntcows++;
          last = stalls[i];
        }
        if(cntcows>=cows) return true;
    }
    return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        int low =0;
        int high = stalls[n-1]-stalls[0];
        while(low<=high){
            int mid = (low+high)>>1;
            if(canWePlace(stalls,mid, k)==true)
                low = mid+1;
            else
                high= mid-1;
        }
        return high;
    }
};