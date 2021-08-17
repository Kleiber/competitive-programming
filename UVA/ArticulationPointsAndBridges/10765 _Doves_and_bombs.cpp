#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 10005

int dfsNumberCounter;
int rootChildren;
int dfs_root;
int dfs_num[MAX];
int dfs_low[MAX];
int dfs_parent[MAX];
vector<int> G[MAX];

int articulation[MAX];
vector< pair<int,int> > bridge;


void articulationPointAndBridge(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;

	for(int j = 0 ; j < G[u].size(); j++){
		int v = G[u][j];

		if(dfs_num[v] == -1){

			dfs_parent[v] = u;

			if(u == dfs_root) rootChildren++;

			articulationPointAndBridge(v);

			if(dfs_low[v] >= dfs_num[u]) articulation[u]++;
			if(dfs_low[v] > dfs_num[u]) bridge.push_back(make_pair(u, v));

			dfs_low[u] = min(dfs_low[u], dfs_low[v]);

		}else{
			if(v != dfs_parent[u]) dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

bool orden( pair<int,int> a , pair<int,int> b){
	if(a.second == b.second) return a.first < b.first;
	else return a.second > b.second;
}

int main(){

	int n,m;
	while(cin>>n>>m && n && m){
		
		for(int i = 0; i < n; i++){
			G[i].clear();
			bridge.clear();
			dfs_parent[i] = -1;
			dfs_num[i] = -1;
			dfs_low[i] = -1;
			articulation[i] = 0;
		}

		int u,v;
		while(cin>>u>>v && u != -1 && v != -1){
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

		vector< pair<int,int> > list;
		for(int i = 0; i < n; i++){
			articulation[i]++;
			list.push_back(make_pair(i, articulation[i]));
		}

		sort(list.begin(), list.end(), orden);

		for(int i = 0; i < m; i++){
			cout<<list[i].first<<" "<<list[i].second<<endl;
		}
		cout<<endl;
	}
}