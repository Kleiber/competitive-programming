#include<iostream>
#include<map>
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

void APoint(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	
	for(int i = 0; i < G[u].size(); i++){
		int v = G[u][i];
		
		if(dfs_num[v] == -1){
			dfs_parent[v] = u;
			
			if(u == dfs_root) root_children++;
			
			APoint(v);
			
			if(dfs_low[v] >= dfs_num[u]) point[u] = 1;
			if(dfs_low[v] > dfs_num[u]) bridge.push_back(make_pair(u,v));
			
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}else{
			if(v != dfs_parent[u]) dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

int main(){
	int N, E, caso = 0;
	string u, v;	
	map<string, int> M;
	map<int, string> M1;
	
	while(cin>>N && N){
		
		if(caso != 0) cout<<endl;
		caso++;
		
		G = vector< vector<int> > (MAX);
		
		for(int i = 0; i < N; i++){
			cin>>u;
			M[u] = i;
			M1[i] = u;
		}
		
		cin>>E;
		for(int i = 0; i < E; i++){
			cin>>u>>v;
			G[M[u]].push_back(M[v]);
			G[M[v]].push_back(M[u]);
		}
		
		bridge = vector< pair<int,int> >();
		
		memset(dfs_num, -1, sizeof(dfs_num));
		memset(dfs_low, 0, sizeof(dfs_low));
		memset(dfs_parent, -1, sizeof(dfs_parent));
		memset(point, 0, sizeof(point));
		
		dfsNumberCounter = 0;
		
		for(int i = 0; i < N; i++){
			if(dfs_num[i] == -1){
				dfs_root = i;
				root_children = 0;
				APoint(i);
				point[dfs_root] = (root_children > 1);
			}
		}
		
		vector<string> ans;
		
		for(int i = 0; i < N; i++){
			if(point[i]) ans.push_back(M1[i]);
		}
		
		sort(ans.begin(), ans.end());
		
		cout<<"City map #"<<caso<<": "<<ans.size()<<" camera(s) found"<<endl;
		for(int i = 0; i < ans.size(); i++) cout<<ans[i]<<endl;
		
		M.clear();
		M1.clear();
	}
	return 0;
}