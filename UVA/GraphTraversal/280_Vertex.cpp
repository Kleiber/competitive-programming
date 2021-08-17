#include<iostream>
#include<cstring>
#include<vector>
#define MAX 105
using namespace std;
vector< vector<int> > V(MAX);
bool visitados[MAX];
int ans;

void dfs(int u){
	for(int i = 0; i < V[u].size(); i++){
		int v = V[u][i];
		if(!visitados[v]){
			visitados[v] = 1;
			ans--;
			dfs(v);
		}
	}
}

int main(){
	int n, q, u, v;
	while(cin>>n && n){
		V = vector< vector<int> >(MAX);
		
		while(cin>>u && u){
			while(cin>>v && v) V[u].push_back(v);
		}
	
		cin>>q;
		for(int i = 0; i < q; i++){
			cin>>u;
			
			ans = n;
			memset(visitados, 0, sizeof(visitados));
			dfs(u);
			
			cout<<ans;
			
			for(int j = 1; j <= n; j++){
				if(!visitados[j]) cout<<" "<<j;
			}
			cout<<endl;
		}
	}
	return 0;
}