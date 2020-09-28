#include <iostream>
using namespace std;

int main() {
	int X, N;
	scanf("%d %d", &X, &N);

	int acum = 0;
	for(int i = 0; i < N; i++) {
		int P;
		scanf("%d", &P);
		acum += P;
	}	

	int ans = X*(N+1) - acum;

	printf("%d\n", ans);

    return 0;
}