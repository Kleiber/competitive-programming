#include<bits/stdc++.h>
using namespace std;
#define MAX 10005

int padre[MAX];

void init(int n){
	for(int i = 0; i < n; i++) padre[i] = i;
}

int find(int x){
	if(x == padre[x]) return x;
	else return find(padre[x]);
}

void join(int x, int y){
	int X = find(x);
	int Y = find(y);
	padre[X] = Y;
}

int nodes(int n){
	int numVertices[MAX];
	memset(numVertices, 0, sizeof(numVertices));
	for(int i = 0; i < n; i++) numVertices[find(i)]++;
	
	int max = 0;
	for(int i = 0; i < n; i++){
		if(numVertices[i] > max) max = numVertices[i];
	}
	return max;
}

int main(){
	int n;
	cin>>n;
	while(n--){
		int N,M,x,y;
		cin>>N>>M;
		init(N);
		for(int i = 0; i < M; i++) cin>>x>>y,join(x,y);
		cout<<nodes(N)<<endl;
	}
	return 0;
}