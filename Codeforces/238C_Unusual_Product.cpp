#include <iostream>
#include<stdio.h>
using namespace std;
int main() {
	int n, q, op, num, ans = 0;
	
	scanf("%d",&n);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			scanf("%d",&num);
			if(i == j) ans += num;
		}
	} 
	
	ans %= 2;
	
	scanf("%d",&q);
	for (int i = 0; i < q; i++) {
		scanf("%d",&op);
		if (op == 1 || op == 2) {
			scanf("%d",&num);
			ans = 1 - ans;
		}else printf("%d",ans);
	}
	printf("\n");
	return 0;
}