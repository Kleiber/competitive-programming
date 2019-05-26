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
#include <iostream>
#define PI 3.1416
using namespace std;  
void mcd(int a, int b){
	long long x,yAnt,r,aIni,bIni,sr,q;
	aIni = a;
	bIni = b;
	x = 1;
	yAnt = 0;
	while(b!= 0){
		r = a %b;
		q = a/b;
		a = b;
		b = r;
		sr = x - yAnt*q;
		x = yAnt;
		yAnt = sr;
	}
	
	cout<<x<<" "<<(a-x*aIni)/bIni<<" "<<a<<endl;
}
int main(){
	long long a,b;
	while(cin>>a>>b){
		mcd(a,b);
	}
	return 0;
}

