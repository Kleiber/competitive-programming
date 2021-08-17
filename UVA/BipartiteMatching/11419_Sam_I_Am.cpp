#include<bits/stdc++.h>
#define MAX 1005
using namespace std;
int R, C, N;
int M[MAX][MAX];
int matchR[MAX], matchC[MAX];
bool visitadosR[MAX], visitadosC[MAX];

int dfs(int r){
	if(visitadosR[r]) return 0;
	visitadosR[r] = 1;
	
	for(int c = 1; c <= C; c++){
		if(M[r][c]){
			if(matchC[c] == -1 || dfs(matchC[c])){
				matchR[r] = c;
				matchC[c] = r;
				return 1;
			}
		}
	}
	return 0;
}

void dfs1(int r){
	if(visitadosR[r]) return;
	visitadosR[r] = 1;
	
	for(int c = 1; c <= C; c++){
		if(M[r][c]){
			visitadosC[c] = 1;
			if(matchC[c] != -1) dfs1(matchC[c]);
		}
	}
}

int main(){
	while(cin>>R>>C>>N && R && C && N){
		
		memset(M, 0, sizeof(M));
	
		int u, v;
		for(int i = 0; i < N; i++){
			cin>>u>>v;
			M[u][v] = 1;
		}
		
		memset(matchR, -1, sizeof(matchR));
		memset(matchC, -1, sizeof(matchC));
		
		int match = 0;
		for(int i = 1; i <= R; i++){
			memset(visitadosR, 0, sizeof(visitadosR));
			if(dfs(i)) match++;
		}
		
		memset(visitadosR, 0, sizeof(visitadosR));
		memset(visitadosC, 0, sizeof(visitadosC));
		
		for(int i = 1; i <= R; i++){
			if(matchR[i] == -1) dfs1(i);
		}
		
		cout<<match;
		for(int i = 1; i <= R; i++){
			if(!visitadosR[i]) cout<<" r"<<i;
		}
		for(int i = 1; i <= C; i++){
			if(visitadosC[i]) cout<<" c"<<i;
		}
		cout<<endl;
	}
	return 0;
}

