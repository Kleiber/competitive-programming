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
	int n,p,m= 0;
	int a,b;
	vector< pair<int,int> > v;
	pair<int,int>x;
	cin>>n;
	for(int  i = 0; i < n; i++){
		cin>>a>>b;
		x = make_pair(a, b);
		v.push_back(x);
	}
	
	for(int  j = 0; j < n; j++){
		if(j == 0)     p = v[j].second - v[j].first;
		else p = p - v[j].first + v[j].second;
		m = max(m,p);
	}
	cout<<m;
    return 0;
}