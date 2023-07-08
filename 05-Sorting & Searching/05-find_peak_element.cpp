class Solution {
public:
    int findPeakElement(vector<int>&v){
        int l=0, h=v.size()-1;
        while(l<h){
            int mid=l+(h-l)/2;
            if(v[mid]<v[mid+1])
                l=mid+1;
            else
                h=mid;
        }
        return l;
    }
};
