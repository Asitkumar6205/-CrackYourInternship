bool sortArr(int a[], int n){
    int x = -1;
    int y = -1;
 
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            if (x == -1) {
                x = i;
            }
            y = i + 1;
        }
    }
 
    if (x != -1) {
        reverse(a + x, a + y + 1);
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                return false;
                return 0;
            }
        }
    }
 
    return true;
}