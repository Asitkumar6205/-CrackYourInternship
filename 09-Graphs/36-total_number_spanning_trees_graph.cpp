#define MAX 100
#define MOD 1000000007
 
// Matrix Multiplication
void multiply(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX])
{
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            for (int k = 0; k < MAX; k++)
                C[i][j] = (C[i][j] + (A[i][k] * B[k][j])%MOD)%MOD;    
}
 
void power(int A[MAX][MAX], int N, int result[MAX][MAX])
{
    int temp[MAX][MAX];
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            result[i][j] = (i == j);
 
    while (N>0){
        if (N%2 == 1){
            multiply(A, result, temp);
            for (int i=0; i<MAX; i++)
                for (int j=0; j<MAX; j++)
                    result[i][j] = temp[i][j];
        }
 
        N = N/2;
        multiply(A, A, temp);
        for (int i=0; i<MAX; i++)
            for (int j=0; j<MAX; j++)
                A[i][j] = temp[i][j];
    }
}
 
int numOfSpanningTree(int graph[][MAX], int V)
{
    int result[MAX][MAX] = {0};
    int temp[MAX][MAX] = {0};
 
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            temp[i][j] = graph[i][j];
 
    power(temp, V-2, result);
 
    int ans = 0;
 
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            ans = (ans + result[i][j])%MOD;
 
    return ans;
}