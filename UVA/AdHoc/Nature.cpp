#include<iostream>
#include<map>
#include<vector>
#include<cstring>
using namespace std;
#define MAX 10005

int padre[MAX];

void init(int n){
	for(int i = 0; i < n; i++) padre[i] = i;
}
int find(int n){
	if(n == padre[n]) return n;
	else return find(padre[n]);
}

void join(int x, int y){
	int X = find(x);
	int Y = find(y);
	padre[X] = Y;
}

int nodes(int n){
	int numVertices[MAX];
	memset( numVertices , 0 , sizeof( numVertices ) );
    for( int i = 0 ; i < n ; i++){
		numVertices[find(i)]++;
	}
	
	int max = 0;
	for(int i = 0; i < n; i++){
		if(numVertices[i] > max) max = numVertices[i];
	}
	return max;
}

int main(){
	int C,R;
	while(cin>>C>>R && (C || R)){
		map<string,int> M;
		string s1,s2;
		init(C);
		int max = 0;
		for(int i = 0; i < C; i++) cin>>s1,M[s1] = i;
		for(int i = 0; i < R; i++) cin>>s1>>s2,join(M[s1],M[s2]);
		cout<<nodes(C)<<endl;
	}
	return 0;
}