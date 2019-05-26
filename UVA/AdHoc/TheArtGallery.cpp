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
bool isConvex(int n,int x[], int y[]){
	int pos=0,neg =0;
	for(int i = 0; i < n; i++){
		int prev = (i + n -1) % n , next = (i  + 1) % n;
		int pv = (x[next] - x[i]) * (y[prev] - y[i]) - (x[prev] - x[i])*(y[next] - y[i]);
		
		if(pv > 0) pos++;
		else {
			if(pv < 0) neg++;
		}
	}
	return (pos == 0) || (neg == 0);
}

int main() {
	int N,a,b;
	cin>>N;
	while(N != 0){
		int x[N], y[N];
		for(int i = 0; i < N; i++){
			cin>>a>>b;
			x[i] = a; y[i] = b;
		}
		if(isConvex(N,x,y)) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
		cin>>N;
	}
	return 0;
}
