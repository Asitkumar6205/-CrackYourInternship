class Solution{
  public:
    int tour(petrolPump p[], int n){
        int totalDiff = 0;
        int fuel = 0;
        int index = 0;
        for(int i=0; i<n; i++){
            int diff = p[i].petrol - p[i].distance;
            totalDiff += diff;
            fuel += diff;
            if(fuel < 0){
                index = i+1;
                fuel = 0;
            }
        }
        return totalDiff < 0 ? -1 : index;
    }
};