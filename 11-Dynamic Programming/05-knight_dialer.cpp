#define ll long long
int mod=1e9+7;
class Solution {
public:
    int knightDialer(int n) {
        vector<ll> prev(10,1);
        vector<ll> curr=prev;ll lastSum=10;
        for(int j=0;j<n-1;j++){
            lastSum=0;
                for(int i=0;i<=9;i++){
                if(i==0) curr[i]=(prev[4]+prev[6])%mod;
                else if(i==1) curr[i]=(prev[6]+prev[8])%mod;
                else if(i==2) curr[i]=(prev[7]+prev[9])%mod;
                else if(i==3) curr[i]=(prev[4]+prev[8])%mod;
                else if(i==4) curr[i]=(prev[3]+prev[9]+prev[0])%mod;
                else if(i==5) curr[i]=0;
                else if(i==6) curr[i]=(prev[7]+prev[1]+prev[0])%mod;
                else if(i==7) curr[i]=(prev[2]+prev[6])%mod;
                else if(i==8) curr[i]=(prev[1]+prev[3])%mod;
                else curr[i]=(prev[4]+prev[2])%mod;
                    lastSum+=curr[i]%mod;
            }
            prev=curr;
        }
        return lastSum%mod;
        
    }
};