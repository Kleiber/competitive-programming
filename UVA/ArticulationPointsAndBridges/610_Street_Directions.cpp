#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
#define MAX 1005

int dfsNumberCounter;
int rootChildren;
int dfs_root;
int dfs_num[MAX];
int dfs_low[MAX];
int dfs_parent[MAX];
vector<int> G[MAX];

int articulation[MAX];
bool bridge[MAX][MAX];

void articulationPointAndBridge(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;

	for(int j = 0 ; j < G[u].size(); j++){
		int v = G[u][j];

		if(dfs_num[v] == -1){

			dfs_parent[v] = u;

			if(u == dfs_root) rootChildren++;

			articulationPointAndBridge(v);

			if(dfs_low[v] >= dfs_num[u]) articulation[u] = 1;
			if(dfs_low[v] > dfs_num[u]) bridge[u][v] = bridge[v][u] = 1;
			else{
				if(!bridge[v][u]) bridge[u][v] = 1;
			}

			dfs_low[u] = min(dfs_low[u], dfs_low[v]);

		}else{
			if(v != dfs_parent[u]){
				dfs_low[u] = min(dfs_low[u], dfs_num[v]);
				if(!bridge[v][u]) bridge[u][v] = 1;
			}
		}
	}
}

int main(){
	int n, m, cases = 0;
	while(cin>>n>>m && n && m){

		cases++;

		for(int i = 0; i < n; i++){
			G[i].clear();
			dfs_parent[i] = -1;
			dfs_num[i] = -1;
			dfs_low[i] = -1;
			articulation[i] = 0;
		}

		memset(bridge, 0, sizeof(bridge));

		for(int i = 0; i < m; i++){
			int u, v;
			cin>>u>>v;
			u--;
			v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}

		dfsNumberCounter = 0;

		for(int i = 0; i < n; i++){
			if(dfs_num[i] == -1){
				dfs_root = i;
				rootChildren = 0;
				articulationPointAndBridge(i);
				articulation[i] = (rootChildren > 1);
			}
		}

		cout<<cases<<endl;
		cout<<endl;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(bridge[i][j]) cout<<i+1<<" "<<j+1<<endl;
			}
		}
		cout<<"#"<<endl;
	}
}