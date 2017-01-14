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
struct Punto{
	double x, y;
	Punto() {}
	Punto(double X, double Y){x =X;y=Y;}
};
Punto operator - (Punto a,Punto b){
	return Punto(a.x - b.x,a.y - b.y);
}
double Pvect(Punto a,Punto b){
	return (a.x*b.y) - (a.y*b.x);
}
double Area(Punto a,Punto b,Punto c){
	return Pvect(b - a, c -a);
}
double isLinea(Punto a,Punto b, Punto c){
	return Area(a,b,c) == 0 ;
}

int main(){
	vector<Punto>V;
	int n,x,y,cont = 0;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>x>>y;
		V.push_back(Punto(x,y));
	}
	cout<<cont<<endl;
return 0;
}
