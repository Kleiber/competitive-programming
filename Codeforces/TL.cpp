#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<stdlib.h>
#include<string>
using namespace std;
#define MAX 10000
int main(){
	int n,m,e,cmax = 0,imin = MAX,tmin = MAX;
	cin>>n>>m;
	
	for(int i = 0; i < n; i++){
		cin>>e;
		if(e > cmax) cmax = e;
		if(2*e < tmin) tmin = 2*e;
	}
	for(int i = 0; i < m; i++){
		cin>>e;
		if(e < imin) imin = e;
	}

	//cout<<cmax<<" "<<tmin<<" "<<imin<<endl;
	if(cmax >= imin || tmin >= imin) cout<<-1<<endl;
	else cout<<max(cmax,tmin)<<endl;
	
	return 0;
}