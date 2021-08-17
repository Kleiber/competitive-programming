#include <iostream>
#include <vector>
using namespace std;
#define MAX 2005

int dfsNumberCounter;
int dfs_num[MAX];
int dfs_low[MAX];
bool visited[MAX];
vector<int> G[MAX];

bool tarjan(int u){
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    visited[u] = true;
    
    for(int j = 0; j < G[u].size(); j++){
    	int v = G[u][j];
        if (dfs_num[v] == -1){
            if (!tarjan(v)) return false;
        }
        if (visited[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    
    if (dfs_low[u] == dfs_num[u] && u != 0) return false;
    return true;
}

bool allVisited(int N){
    for (int i = 0; i < N; i++){
        if (!visited[i]) return false;
    }
    return true;
}

int main(){
    int N, M;
    
    while(cin>>N>>M && N != 0 && M != 0) {

        for (int i = 0; i < N; i++){
	    G[i].clear();
            dfs_num[i] = -1;
            dfs_low[i] = -1;
            visited[i] = 0;
        }
        
        for(int i = 0; i < M; i++){
            int V, W, P;
            cin>>V>>W>>P;
            V--; 
            W--;
            G[V].push_back(W);
            if (P == 2) G[W].push_back(V);
        }
        
        dfsNumberCounter = 0;

        if (tarjan(0) && allVisited(N)) cout<<"1"<<endl;
        else cout<<"0"<<endl;
    }
}
