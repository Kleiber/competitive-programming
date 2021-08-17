#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define MAX 10005

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
	int cases = 1;
	int T;
	cin>>T;

	while(T--){
		int N, M, A;
		cin>>N>>M>>A;

		vector<edge> V;

		for(int i = 0; i < M; i++){
			int u, v, w;
			cin>>u>>v>>w;
			V.push_back((edge){u, v, w});
		}

		sort(V.begin(), V.end(), order);
		Init();

		int cost = N*A;
		int airports = N;
		for(int i = 0; i < V.size(); i++){
			if(!sameComponent(V[i].u, V[i].v)){
				if(cost - A + V[i].w < cost){
					cost = cost - A + V[i].w;
					airports--;
				}
				Union(V[i].u, V[i].v);
			}
		}

		cout<<"Case #"<<cases++<<": "<<cost<<" "<<airports<<endl;
	}

	return 0;
}