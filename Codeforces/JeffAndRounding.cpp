#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int N;
double A[4005], D[4005][4005];

double min(double a, double b) {
    if(abs(a) < abs(b)) return a;
    return b;
}

int main() {
    cin>>N;
    for(int i = 1; i <= 2*N; i++) cin>>A[i];
	
    for(int i = 1; i <= N; i++) D[0][i] = 1LL<<60;
	
    for(int i = 1; i <= 2*N; i++) {
        D[i][0] = D[i - 1][0] + ceil(A[i]) - A[i];
		mostrar(N);
        for(int j = 1; j <= N; j++) {
            D[i][j] = min(D[i - 1][j] + ceil(A[i]) - A[i], D[i - 1][j - 1] + floor(A[i]) - A[i]);
        }
    }
	
    printf("%.3lf\n", abs(D[2 * N][N]));
    return 0;
}