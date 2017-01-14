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
#define PI  3.14159
using namespace std;
double distancia(double x1, double y1, double x2, double y2){
	double d = (x1-x2)*(x1-x2) +  (y1-y2)*(y1-y2);
	return sqrt(d);
}
int main(){
	vector< pair<double,double> >P;
	pair<double,double>p;
	int n;
	double r,x,y,dist =0.0;
	cin>>n>>r;
	for(int  i = 0; i < n; i++){
		cin>>x>>y;
		p = make_pair(x, y);
		P.push_back(p);
	}
	for(int i = 0; i < n; i++){
		dist += distancia(P[i].first,P[i].second,P[(i+1) % n].first,P[(i+1)%n].second);
	}
	dist+=2*PI*r;
	printf("%0.2f\n",dist);
return 0;
}
