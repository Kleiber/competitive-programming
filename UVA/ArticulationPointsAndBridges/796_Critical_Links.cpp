#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<sstream>
#include<cstring>
#include<algorithm>
#define MAX 101
using namespace std;
vector< vector<int> > G;
vector< pair<int,int> > bridge;
bool point[MAX];
int dfs_low[MAX], dfs_num[MAX], dfs_parent[MAX];
int dfs_root, root_children, dfsNumberCounter;

void ABridge(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	
	for(int i = 0; i < G[u].size(); i++){
		int v = G[u][i];
		
		if(dfs_num[v] == -1){
			dfs_parent[v] = u;
			
			if(u == dfs_root) root_children++;
			
			ABridge(v);
			
			if(dfs_low[v] >= dfs_num[u]) point[u] = 1;
			if(dfs_low[v] > dfs_num[u]){
				bridge.push_back(make_pair( min(u,v), max(u,v) ));
			}
			
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}else{
			if(v != dfs_parent[u]) dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

int main(){
	int N, v, n, u;
	bool f = 0;
	string s;
	
	while(cin>>N){
		
		G = vector< vector<int> > (MAX);
		
		for(int i = 0; i < N; i++){
			cin>>v;
			
			cin>>s;
			int n = atoi((s.substr(1, s.size() - 2)).c_str());
			
			for(int j = 0; j < n; j++){
				cin>>u;
				G[v].push_back(u);
				G[u].push_back(v);
			}
		}
		
		bridge = vector< pair<int,int> > ();
		
		memset(dfs_num, -1, sizeof(dfs_num));
		memset(dfs_low, 0, sizeof(dfs_low));
		memset(dfs_parent, -1, sizeof(dfs_parent));
		memset(point, 0, sizeof(point));
	
		dfsNumberCounter = 0;
		
		for(int i = 0; i < N; i++){
			if(dfs_num[i] == -1){
				dfs_root = i;
				root_children = 0;
				ABridge(i);
				point[dfs_root] = (root_children > 1);
			}
		}
		
		sort(bridge.begin(), bridge.end());
		
		cout<<bridge.size()<<" critical links"<<endl;
		for(int i = 0; i < bridge.size(); i++){
			cout<<bridge[i].first<<" - "<<bridge[i].second<<endl;
		}
		cout<<endl;
	}
	return 0;
}

