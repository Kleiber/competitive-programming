#include<iostream>
#include<string>
#include<vector>
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
	int N, u, v;
	string s;
	while(cin>>N && N){
		getline(cin,s);
		
		G = vector< vector<int> >(MAX);
	
		while(1){
			getline(cin,s);
			
			stringstream in(s);
			
			in>>u;
			if(u == 0) break;
			u--;
			
			while(in>>v){
				v--;
				G[u].push_back(v);
				G[v].push_back(u);
			}
		}
		
		bridge = vector< pair<int,int> > (MAX);
		
		memset(dfs_num, -1, sizeof(dfs_num));
		memset(dfs_low, 0, sizeof(dfs_low));
		memset(dfs_parent, -1, sizeof(dfs_parent));
		memset(point, 0, sizeof(point));
		
		dfsNumberCounter = 0;
		
		root_children = 0;
		dfs_root = 0;
		APoint(0);
		point[0] = (root_children > 1);
		
		
		int ans = 0;
		for(int i = 0; i < N; i++){
			if(point[i]) ans++;
		}
		
		cout<<ans<<endl;
	}
	return 0;
}