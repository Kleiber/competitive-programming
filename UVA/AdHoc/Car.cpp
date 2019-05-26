#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int main(){
	int cases = 0;
	while(true){
		cases++;
		int op;
		double a,b,c,x = 0,y = 0;
		cin>>op;
		if(op == 0) break;
		cin>>a>>b>>c;
		
		if(op == 1){y = (b - a)/c; x = a*c + y*c*c/2;}
		if(op == 2){y = (b - a)/c; x = a*y + c*y*y/2;}
		if(op == 3){x = sqrt(a*a + 2*b*c); y = (x - a)/b;}
		if(op == 4){x = sqrt(a*a - 2*b*c); y = (a - x)/b;}
		
		printf("Case %d: %.3f %.3f\n",cases,x,y);
	}
	return 0;
}