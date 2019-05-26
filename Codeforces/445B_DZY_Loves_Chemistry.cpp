#include<bits/stdc++.h>
#define MAX 55
using namespace std;
int padre[MAX];

void Init(int n){
	for(int i = 1; i <= n; i++) padre[i] = i;
}

int Find(int x){
	if(x == padre[x]) return x;
	else return padre[x] = Find(padre[x]);
}

void Union(int x, int y){
	int X = Find(x);
	int Y = Find(y);
	
	padre[X] = Y;
}

int main(){
	int n, m, x, y;
	cin>>n>>m;
	
	Init(n);
	
	for(int i = 0; i < m; i++){
		cin>>x>>y;
		Union(x,y);
	}
	
	long long ans = n;
	
	for(int i = 1; i <= n; i++){
		if(i == padre[i]) ans--;
	}
	
	cout<<(1ll<<ans)<<endl;
	return 0;
}