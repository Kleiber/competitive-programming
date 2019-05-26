#include<iostream>
#include<cstring>
#include<vector>
#define MAX 200005
using namespace std;
vector< vector<int> > G(MAX);
bool visitados[MAX];
int V[MAX], H[MAX], A[MAX], B[MAX], tree[2*MAX], cont = 0;

int dfs(int nodo){
	visitados[nodo] = 1;
	A[nodo] = ++cont;
	
	for(int i = 0; i < G[nodo].size(); i++){
		if(!visitados[G[nodo][i]]){
			H[G[nodo][i]] = H[nodo] + 1;
			dfs(G[nodo][i]);
		}
	}
	B[nodo] = ++cont;
	return 0;
}

void update(int nodo, int val){
	while(nodo <= cont){
		tree[nodo] += val;
		nodo += nodo&(-nodo);
	}
}

int query(int nodo){
	int ans = 0;
	while(nodo){
		ans += tree[nodo];
		nodo -= nodo&(-nodo);
	}
	return ans;
}

int main(){
	int n, m, u, v, op, nodo, val;
	cin>>n>>m;
	
	for(int i = 1; i <= n; i++) cin>>V[i];
	
	for(int i = 0; i < n - 1; i++){
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	memset(visitados,0, sizeof(visitados));
	dfs(1);
	
	for(int i = 0; i < m; i++){
		cin>>op;
		if(op == 1){
			cin>>nodo>>val;

			if(H[nodo] % 2 == 1) val = -val;			
	
			update(A[nodo], val);
			update(B[nodo], -val);

		}else{
			cin>>nodo;
			int ans = V[nodo];
			if(H[nodo] % 2 == 0) ans = ans + query(A[nodo]);
			else ans = ans - query(A[nodo]);
			
			cout<<ans<<endl;
		}
	}
	
	return 0;
}