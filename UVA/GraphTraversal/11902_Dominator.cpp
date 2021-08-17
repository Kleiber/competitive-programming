#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define MAX 105
using namespace std;
int T,N,e;
vector< vector<int> > G(MAX);
bool ans[MAX][MAX], visitados1[MAX], visitados[MAX];

void dfs(int nodo, int des){
	
	visitados[nodo] = 1;
	
	if(nodo == des) return;
	
	for(int i = 0; i < G[nodo].size(); i++){
		if(!visitados[G[nodo][i]]){
			dfs(G[nodo][i], des);
		}
	}
}

int main(){
	cin>>T;
	for(int k = 1; k <= T; k++){
		
		cin>>N;	
		
		memset(visitados, 0, sizeof(visitados));
		G = vector< vector<int> >(MAX);
		
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				cin>>e;
				if(e == 1) G[i].push_back(j);
			}
		}
		
		dfs(0, -1);
		memset(ans, 0, sizeof(ans));
		
		for(int i = 0; i < MAX; i++) visitados1[i] = visitados[i];
		
		for(int i = 0; i < N; i++){
			memset(visitados, 0, sizeof(visitados));
				dfs(0, i);
			for(int j = 0; j < N; j++){
				if(visitados1[j] && !visitados[j]) ans[i][j] = 1;
				else ans[i][j]= 0;
			}
			ans[i][i] = visitados1[i];
		}
		
		cout<<"Case "<<k<<":"<<endl;
		
		string s = "+";
		for(int i = 0; i < 2*N - 1; i++) s += "-";
		s+="+";
		cout<<s<<endl;
		for(int i = 0; i < N; i++){
			cout<<"|";
			for(int j = 0; j < N; j++){
				if(ans[i][j]) cout<<"Y|";
				else cout<<"N|";
			}
			cout<<endl;
			cout<<s<<endl;
		}
	
	}
	return 0;
}
