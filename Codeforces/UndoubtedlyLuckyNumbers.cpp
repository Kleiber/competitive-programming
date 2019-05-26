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
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include<string.h>
#include <iostream>
#define ll long long int
using namespace std;

set < ll > S;
void bfs(ll n,ll a,ll b,ll p){
	if(p == 0) return;
	if(n) S.insert(n);
	bfs(n*10+a,a,b,p-1);
	bfs(n*10+b,a,b,p-1);
}
int main(){
	for(ll i = 0;i < 10;i++)
		for(ll j = i + 1;j < 10;j++) bfs(0,i,j,11);
	vector < ll > V(S.begin(),S.end());
	
	ll n;
	cin>>n;
	//cout<<V[V.size()-1]<<endl;
	for(ll i = 0; i < V.size() ; i++) if(V[i]>n){
		cout<<i<<endl;
		return 0;
	}
	//cout<<V.size()<<endl;
    return 0;
}