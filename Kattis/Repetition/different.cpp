#include <iostream>
#include<cmath>
using namespace std;

int main() {
	long long int A, B;
	while(scanf("%lld %lld", &A, &B) != EOF) {
		printf("%lld\n", abs(A - B));
	}
    return 0;
}