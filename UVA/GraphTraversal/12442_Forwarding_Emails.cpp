#include<iostream>
#include<cstring>
#include<vector>
#define MAX 50005
using namespace std;
vector<int> V(MAX);
int suma[MAX];
bool visitados[MAX];

int dfs(int u){
	visitados[u] = 1;
	int total = 0;
	
	int v = V[u];
	if(!visitados[v]) total += 1 + dfs(v);
	
	visitados[u] = 0;
	
	return suma[u] = total;
}

int main(){
	int casos, n, u, v;
	cin>>casos;
	
	for(int i = 1; i <= casos; i++){
		cin>>n;
		
		memset(visitados, 0, sizeof(visitados));
		memset(suma, 0, sizeof(suma));
		V = vector<int>(MAX);
		
		for(int j = 0; j < n; j++){
			cin>>u>>v;
			V[u] = v;
		}
		
		int ind = 0, ans = 0;
		
		for(int j = 1; j <= n; j++){
			if(suma[j] == 0) dfs(j);
			if(suma[j] > ans){
				ans = suma[j];
				ind = j;
			}
		}
		cout<<"Case "<<i<<": "<<ind<<endl;
	}
	
	return 0;
}