#include <cstdio>
using namespace std;

void process(int N, long B, int H, int W) {
	long mn = 1000000000;
	while (H--) {
		int w=W, p, a;
			scanf("%d\n", &p);
			while(w-- && scanf("%d", &a) == 1)
				if (a >= N && N*p < mn)
					mn = N*p;
	}
	
	mn <= B ? printf("%ld\n", mn) : printf("stay home\n");
	scanf("\n");
}

int main(){
	int N, H, W;
	long B;
	char line[1000];
	while (gets(line)) {
		sscanf(line, "%d %ld %d %d", &N, &B, &H, &W);
		process(N, B, H, W);
	}
}
