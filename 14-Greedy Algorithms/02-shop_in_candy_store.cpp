class Solution{
public:
     vector<int> candyStore(int candies[], int N, int k){
       sort(candies,candies+N);
       int min=0;
       int i=0;
       int j=N-1;
       while(i<=j){
           min+=candies[i];
           i++;
           j-=k;
       }
       i=0;
       j=N-1;
       int max=0;
       while(i<=j){
           max+=candies[j];
           j--;
           i+=k;
       }
       return {min,max};
    }
};