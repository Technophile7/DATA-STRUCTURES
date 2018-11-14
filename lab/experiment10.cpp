#include<iostream>
using namespace std;
int merge(int *A, int M, int *B, int N, int *C)
{ //Enter your code here
        int p = 0;
        int q = 0;
        int k = 0;
        int c=0;
while ( p < M && q < N) {
if (A[p] < B[q])
                {
C[k++] = A[p++];
c++;
                }
            else {
C[k++] = B[q++];
 c++;               }
}
while ( p < M) {
         C[k++] = A[p++];
            }
while ( q < N) {
         C[k++] = B[q++];
            }
    return c;
}

int main()
{
    int i,M,N;
    cin >> M >> N;
    int A[M],B[N],C[M+N];
    int X;
    for(i=0;i<=M-1;i++)
        cin >> A[i];
    for(i=0;i<=N-1;i++)
        cin >> B[i];
    X = merge(A,M,B,N,C);
    for(i=0;i<=M+N-1;i++)
        cout << C[i] << " ";
    cout << endl << X;
    return 0; }
