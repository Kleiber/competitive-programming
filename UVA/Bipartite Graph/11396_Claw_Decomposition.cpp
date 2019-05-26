#include<iostream>
#include<vector>
#include<queue>
#define MAX 305
#define INF 2000000000
using namespace std;
int N;
vector< vector<int> > G(MAX);
vector<int> color(MAX, INF);

bool Bipartite(int nodo){
	queue<int> Q;
	Q.push(nodo);
	color[nodo] = 0;
	
	bool isBipartite = 1;
	
	while(!Q.empty() && isBipartite){
		nodo = Q.front();
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
	}
	return isBipartite;
}

int main(){
	while(cin>>N && N){
		
		int u,v;
		G = vector< vector<int> >(MAX);
		color = vector<int>(MAX, INF);
		
		while(cin>>u>>v && u && v){
			G[u].push_back(v);
			G[v].push_back(u);
		}
		
		if(Bipartite(1))cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
	return 0;
}
