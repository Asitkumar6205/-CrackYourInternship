class Solution {
public:
    int removeDuplicates(vector<int> &v) {
        int s = v.size();
        int i=0;       
        for(int j=1; j<s; j++){
            if(v[i] != v[j]){
                i++;
                v[i] = v[j];
            }
        }
        return i+1;
    }
};