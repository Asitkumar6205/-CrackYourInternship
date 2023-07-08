
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    vector<int> arr = { 1, 2, 8, 10, 10, 12, 19 };
    int n = arr.size();
    int x = 8;
    auto itr = lower_bound(arr.begin(), arr.end(),x); // returns iterator
    int idx = itr - arr.begin(); // converting to index;
    if (idx == n) {
        cout << "Ceil Element does not exist " << endl;
    }
    else {
        cout << "Ceil Element of " << x << " is " << arr[idx] << endl;
    }
    return 0;
}