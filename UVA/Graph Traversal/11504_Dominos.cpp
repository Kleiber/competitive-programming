#include<iostream>
#include<vector>
#include<stack>
#include<map>
using namespace std;
#define MAX 100001

int num_scc;
int dfsNumberCounter;
vector<bool> visited;
vector<int> dfs_num, dfs_low;
vector< vector<int> > G, GG;
stack<int> S;
map<int,int> M;

void tarjan(int u){
	dfs_num[u] = dfs_low[u] = dfsNumberCounter++;
	visited[u] = 1;
	S.push(u);

	for(int j = 0; j < G[u].size(); j++){
		int v = G[u][j];
		if(dfs_num[v] == -1) tarjan(v);
		if(visited[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}

	if(dfs_low[u] == dfs_num[u]){
		while(1){
			int v = S.top();
			S.pop();
			visited[v] = 0;
			M[v] = num_scc;
			if (u == v) break;
		}
		num_scc++;
	}
}

int main(){
	int cases, n, m;
	cin>>cases;
	while(cases--){
		cin>>n>>m;

        G.clear();
        G.resize(n);

        dfs_num.assign(n, -1);
		dfs_low.assign(n, -1);
		visited.assign(n,  0);

        M.clear();
        
		for(int i = 0; i < m; i++){
			int x, y;
			cin>>x>>y;
			x--;
			y--;
			G[x].push_back(y);
		}

		num_scc = 0;
		dfsNumberCounter = 0;

		for(int i = 0; i < n; i++){
			if(dfs_num[i] == -1) tarjan(i);
		}

		GG.clear();
		GG.resize(num_scc);

		for(int i = 0; i < n; i++){
			for(int j = 0; j < G[i].size(); j++){
				if(M[i] != M[G[i][j]]) GG[M[i]].push_back(M[G[i][j]]);
			}
		}

		vector<int> indegree(num_scc, 0);
		for(int i = 0; i< num_scc; i++){
			for(int j = 0; j < GG[i].size(); j++){
				indegree[GG[i][j]] = 1;
			}
		}

		int ans = 0;
		for (int i = 0; i < num_scc; i++){
			if(indegree[i] == 0) ans++;
		}
		cout<<ans<<endl;
		
	}
	return 0;
}