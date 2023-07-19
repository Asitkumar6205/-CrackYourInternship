class Solution {
public:
    bool isPalindrome(int x) {
        int r=0;
        if(x<0 || (x%10==0 && x!=0))
            return false;
        while(x>r){
            r=r*10 + x%10;
            x/=10;
        }
    return x==r|| x==r/10;
    }
};