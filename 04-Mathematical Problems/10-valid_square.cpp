class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
       bool ans = false;
       int d1 = (pow((p2[1]-p1[1]),2)+pow((p2[0]-p1[0]),2));
       int d2 = (pow((p3[1]-p1[1]),2)+pow((p3[0]-p1[0]),2));
       int d3 = (pow((p4[1]-p1[1]),2)+pow((p4[0]-p1[0]),2));
       int d4 = (pow((p4[1]-p2[1]),2)+pow((p4[0]-p2[0]),2));
       int d5 = (pow((p3[1]-p2[1]),2)+pow((p3[0]-p2[0]),2));
       int d6 = (pow((p4[1]-p3[1]),2)+pow((p4[0]-p3[0]),2));
       if(d1==0 || d2==0 || d3==0|| d4==0|| d5==0|| d6==0) return ans;
       set<int> s;
       s.insert(d1);
       s.insert(d2);
       s.insert(d3);
       s.insert(d4);
       s.insert(d5);
       s.insert(d6);
       if(s.size()==2) ans = true;
       return ans;
    }
};