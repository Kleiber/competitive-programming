#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 1000005

struct edge{
	int u, v, w;
};

int padre[MAX];

void Init(){
	for(int i = 0; i < MAX; i++) padre[i] = i;
}

int Find(int x){
	if(x == padre[x]) return x;
	else return padre[x] = Find(padre[x]);
}

void Union(int x, int y){
	int X = Find(x);
	int Y = Find(y);
	padre[Y] = X;
}

bool sameComponent(int x, int y){
	if(Find(x) == Find(y)) return 1;
	else return 0;
}

bool order(edge a, edge b){
	return a.w < b.w;
}

int main(){
	int n, m;
	while(cin>>n>>m){

		if(n == 0 && m == 0) break;

		vector<edge> V;
		for(int i = 0; i <  m; i++){
			int u, v, w;
			cin>>u>>v>>w;
			V.push_back((edge){u, v, w});
		}

		sort(V.begin(), V.end(), order);
		Init();

		int cost = 0;
		int components = n;
		for(int i = 0; i < V.size(); i++){
			if(!sameComponent(V[i].u, V[i].v)){
				cost = max(cost, V[i].w);
				components--;
				Union(V[i].u, V[i].v);
			}
		}

		if(components > 1) cout<<"IMPOSSIBLE"<<endl;
		else cout<<cost<<endl;

	}
	return 0;
}