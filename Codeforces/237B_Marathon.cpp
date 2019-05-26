#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	double a,d,pos, x, y;
	long long n, lado;
	
	cin>>a>>d>>n;
	
	for(long long i = 1; i <= n; i++){
		
		lado = i*d / a;
		pos = i*d - lado * a;
		lado %= 4;
		
		if(lado == 0){
			x = pos;
			y = 0;
		}
		if(lado == 1){
			x = a;
			y = pos;
		}
		if(lado == 2){
			x = a - pos;
			y = a;
		}
		if(lado == 3){
			x = 0;
			y = a - pos;
		}
		
		printf("%.10f %.10f\n",x,y);
	}

	return 0;
}