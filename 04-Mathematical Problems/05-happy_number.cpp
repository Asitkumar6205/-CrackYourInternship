class Solution {
public:
    bool isHappy(int n) {
        while(n>9){
            int sum = 0;
            int m = n;
            while(m>0){
                int a = m%10;
                sum+= (a*a);
                m/=10;
            }
            n = sum;
        }
        return (n==1 or n==7) ? true : false;
    }
};