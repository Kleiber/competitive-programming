#include<bits/stdc++.h>
using namespace std;
int main(){
	int H, M;
	char c;
	while(scanf("%d%c%d",&H, &c, &M) && (H || M)){
	
		double horario, minutero, ans;
		
		if(H == 12) H = 0;
		horario = 30.0 * (double)H + ((double)M/60) * 30.0;
		minutero = (double)M * 6.0;
		
		if(abs(horario - minutero) > 180) ans = 360.0 - abs(horario - minutero);
		else ans = abs(horario - minutero);
		
        printf("%.3f\n", ans);
	}
	return 0;
}