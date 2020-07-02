#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define MAX 100005

vector<int> G[MAX];
bool visited[MAX];
int faces;

void dfs(int u){
	visited[u] = 1;
	for(int j = 0; j < G[u].size(); j++){
		int v = G[u][j];
		if(!visited[v]) dfs(v);
		else faces++;
	}
}

int main(){
	int N, E;
	while(cin>>N>>E){

		for(int i = 0; i < N; i++){
			G[i].clear();
			visited[i] = 0;
		}

		map<char, int> M;
		int cont = 0;

		for(int i = 0; i < E; i++){
			char u, v;
			cin>>u>>v;
			if(M.find(u) == M.end()) M[u] = cont++;
			if(M.find(v) == M.end()) M[v] = cont++;
			G[M[u]].push_back(M[v]);
		}

		faces = 1;
		for(int i = 0; i  < N; i++){
			if(!visited[i]) dfs(i);
		}

		cout<<faces<<endl;
	}
	return 0;
}