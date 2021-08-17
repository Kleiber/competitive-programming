#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
#define MAX 405

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
	int s, c;
	while(cin>>s>>c){

		if(s == 0 && c == 0) break;

		map<string, int> M;
		for(int i = 0; i < s; i++){
			string s;
			cin>>s;
			M[s] = i;
		}

		vector<edge> V;
		for(int i = 0; i < c; i++){
			string u, v;
			int w;
			cin>>u>>v>>w;
			V.push_back((edge){M[u], M[v], w});
		}

		string start;
		cin>>start;

		sort(V.begin(), V.end(), order);
		Init();

		int cost = 0;
		int components = s;
		for(int i = 0; i < V.size(); i++){
			if(!sameComponent(V[i].u, V[i].v)){
				cost += V[i].w;
				components--;
				Union(V[i].u, V[i].v);
			}
		}

		if(components > 1) cout<<"Impossible"<<endl;
		else cout<<cost<<endl;
	}

	return 0;
}