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
using namespace std;
int main()
{
	int n,k;
	vector< pair<double,double> > v;
	double d = 0;
	cin>>n>>k;
	double a,b;
	for(int i = 0; i < n; i++){
		cin>>a>>b;	
		pair<double,double>x;
		x = make_pair(a, b);
		v .push_back(x);
	}
	
	for(int i = 0; i < n - 1; i++){
		d += hypot(v[i+1].first - v[i].first, v[i+1].second - v[i].second);
		cout<<"distancia (" <<v[i].first <<","<<v[i].second<<" -->"<< v[i+1].first <<","<< v[i+1].second<<"] =    "<<d<<endl;
	}
	printf("%.9f",k*d/50);
    return 0;
}