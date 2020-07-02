#include<iostream>
#include<vector>
#include<stack>
#include<map>
using namespace std;
#define MAX 30

int num_scc;
int dfsNumberCounter;
bool visited[MAX];
int dfs_num[MAX];
int dfs_low[MAX];
vector<int> G[MAX];
stack<int> S;
map<string, int> M1;
map<int, string> M2;

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
		int v = S.top();
		S.pop();
		visited[v] = 0;
		cout<<M2[v];
		while(u != v){
			v = S.top();
			S.pop();
			visited[v] = 0;
			cout<<", "<<M2[v];
		}
		cout<<endl;
		num_scc++;
	}
}

int main(){
	int n, m;
	int id, cases = 1;

	while(cin>>n>>m && n != 0 && m != 0){
		id = 0;
        M1.clear();
        M2.clear();

        for(int i = 0; i < n; i++){
        	G[i].clear();
        	dfs_num[i] = -1;
        	dfs_low[i] = -1;
        	visited[i] =  0;
        }
        
		for(int i = 0; i < m; i++){
			string u, v;
			cin>>u>>v;

			if(M1.find(u) == M1.end()) M1[u] = id, M2[id++] = u;
			if(M1.find(v) == M1.end()) M1[v] = id, M2[id++] = v;

			G[M1[u]].push_back(M1[v]);
		}
		
		num_scc = 0;
		dfsNumberCounter = 0;

		cout<<"Calling circles for data set "<<cases++<<":"<<endl;

		for(int i = 0; i < n; i++){
			if(dfs_num[i] == -1) tarjan(i);
		}
	}
	return 0;
}
