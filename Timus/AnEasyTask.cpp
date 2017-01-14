#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>  
#include <cstdlib>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
using namespace std;
double CalcularX(double a1,double b1,double c1,double a2,double b2, double c2){
	return (b1*c2 - b2*c1)/(a2*b1 - a1*b2);
}

double CalcularY(double a1,double b1,double c1,double a2,double b2, double c2){
	return (c2 - a2*CalcularX(a1,b1,c1,a2,b2,c2))/b2;
}

int main(){
	double a1,b1,c1,a2,b2,c2;
	while(1){
		cin>>a1>>b1>>c1;
		cin>>a2>>b2>>c2;
		if(a1== 0 && b1 == 0 && c1 ==0 && a2 == 0 && b2 == 0 && c2 == 0) break;
		
		if((a2*b1 - a1*b2) ==0) printf("No fixed point exists.\n");
		else printf("The fixed point is at %0.2f %0.2f.\n",CalcularX(a1,b1,c1,a2,b2,c2),CalcularY(a1,b1,c1,a2,b2,c2));
	} 
	return 0;
}
