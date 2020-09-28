#include <iostream>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	double ans = 0;
	for(int i = 0; i < N; i++) {
		double q, y;
		scanf("%lf %lf", &q, &y);
		ans += q*y;
	}	

	printf("%.3lf\n", ans);

    return 0;
}