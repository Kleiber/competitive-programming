#include<iostream>
#include<vector>
#include<queue>
#define MAX 205
#define INF 2000000000
using namespace std;
int N,E;
bool isBipartite;
vector< vector<int> > G(MAX);
vector<int> color(MAX,INF);

void Bipartite(int nodo){
	queue<int> Q;
	Q.push(nodo);
	color[nodo] = 0;
	
	isBipartite = 1;
	
	while(!Q.empty()){
		int nodo = Q.front();
		Q.pop();
		
		for(int i = 0; i < G[nodo].size(); i++){
			int v = G[nodo][i];
			if(color[v] == INF){
				color[v] = 1 - color[nodo];
				Q.push(v);
			}else{
				if(color[v] == color[nodo]){
					isBipartite = 0;
					break;
				}
			}
		}
		
		if(isBipartite) break;
	}
}

int main(){
	while(cin>>N && N){
		cin>>E;
		
		int u,v;
		G = vector< vector<int> > (MAX);
		color = vector<int> (MAX, INF);
		
		for(int i = 0; i < E; i++){
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		
		Bipartite(0);
		
		if(isBipartite) cout<<"BICOLORABLE."<<endl;
		else cout<<"NOT BICOLORABLE."<<endl;
	}
	return 0;
}

