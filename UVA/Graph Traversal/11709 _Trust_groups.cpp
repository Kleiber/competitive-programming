#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
using namespace std;
#define MAX 1005

int num_scc;
int dfsNumberCounter;
bool visited[MAX];
int dfs_num[MAX];
int dfs_low[MAX];
vector<int> G[MAX];
map<string, int> M;
stack<int> S;

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
			if(u == v) break;
		}
		num_scc++;
	}
}

int main(){
	int n, m;
	int id;
	string name;

	while(cin>>n>>m){
		getline(cin,name);

		if(n == 0 && m == 0) break;

		id = 0;
        M.clear();

        for(int i = 0; i < n; i++){
        	G[i].clear();
        	dfs_num[i] = -1;
        	dfs_low[i] = -1;
        	visited[i] =  0;

        	getline(cin,name);
        	M[name] = id++;
        }        
        
		for(int i = 0; i < m; i++){
			string u, v;
			getline(cin,u);
			getline(cin,v);

			G[M[u]].push_back(M[v]);
		}
		
		num_scc = 0;
		dfsNumberCounter = 0;

		for(int i = 0; i < n; i++){
			if(dfs_num[i] == -1) tarjan(i);
		}

		cout<<num_scc<<endl;
	}
	return 0;
}
