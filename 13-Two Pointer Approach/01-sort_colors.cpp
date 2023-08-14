class Solution {
public:
    void sortColors(vector<int>& a) {
        int l=0;
        int m=0;
        int h=a.size()-1;
        while(m<=h){
            if(a[m]==0)
                swap(a[l++], a[m++]);
            else if(a[m]==1)
                m++;
            else
                swap(a[h--], a[m]);
        }
    }
};