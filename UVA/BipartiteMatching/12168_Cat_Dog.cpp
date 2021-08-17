#include<bits/stdc++.h>
#define MAX 1005
using namespace std;
bool visitados[MAX], M[MAX][MAX];
int match[MAX];
int votos[2][MAX];
int C, D, V;

bool dfs(int u){
	for(int i = 0; i < V; i++){
		if(!visitados[i] && M[u][i]){
			visitados[i] = 1;
			if(match[i] == -1 || dfs(match[i])){
				match[i] = u;
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	int casos;
	cin>>casos;
	
	while(casos--){
		
		cin>>C>>D>>V;
		
		char l;
		int num;
		memset(votos, -1, sizeof(votos));
		
		for(int i = 0; i < V; i++){
			cin>>l>>num;
			num--;
			if(l == 'D') num += C;
			votos[0][i] = num;
			
			cin>>l>>num;
			num--;
			if(l == 'D') num += C;
			votos[1][i] = num;
		}
		
		memset(M, 0, sizeof(M));
		
		for(int i = 0; i < V; i++){
			for(int j = 0; j < V; j++){
				if(votos[0][i] == votos[1][j] || votos[1][i] == votos[0][j]){
					M[i][j] = 1;
				}
			}
		}
		
		int ans = 0;
		memset(match, -1, sizeof(match));
		
		for(int i = 0; i < V; i++){
			memset(visitados, 0, sizeof(visitados));
			if(dfs(i)) ans++;
		}
	
		cout<<V - ans/2<<endl;
	}
	return 0;
}
