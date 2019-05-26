#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long e[100010];
int t[100010],x[100010],l[100010],c[100010];

int find(int u,long long p){

	if(t[u] == 1) return x[u];
	
	long long tmp = p - e[u - 1] - 1;
	
	tmp = tmp % l[u];
	tmp++;
	
	
	u = lower_bound(e, e + u, tmp) - e;
	
	return find(u,tmp);
}

int main(){
	int m;
	cin>>m;
	e[0] = 0;
	
	for(int i = 1; i <= m; i++){
		cin>>t[i];
		if(t[i] == 1){
			cin>>x[i];
			e[i] = e[i-1] + 1;
		}
		else{
			cin>>l[i]>>c[i];
			e[i] = e[i-1] + (long long)(l[i] * c[i]);
		}
	}
	
	/*
	for(int i = 0; i < 16; i++) cout<<x[i]<<" ";
	cout<<endl;
	for(int i = 0; i < 16; i++) cout<<t[i]<<" ";
	cout<<endl;
	for(int i = 0; i < 16; i++) cout<<l[i]<<" ";
	cout<<endl;
	for(int i = 0; i < 16; i++) cout<<c[i]<<" ";
	cout<<endl;
	for(int i = 0; i < 16; i++) cout<<e[i]<<" ";
	cout<<endl;
	*/
	
	int n;
	cin>>n;
	
	for(int i = 0; i < n; i++){
		long long tmp;
		cin>>tmp;
		int u = lower_bound(e, e + m + 1, tmp) - e;
		cout<<find(u, tmp)<<" ";
	}
	return 0;
}