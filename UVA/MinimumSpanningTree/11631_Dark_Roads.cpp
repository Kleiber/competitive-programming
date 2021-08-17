#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define MAX 200005

int padre[MAX];

void init(int n){
	for(int i = 0; i < n; i++) padre[i] = i;
}

int Find(int x){
	if(x == padre[x]) return x;
	else return padre[x] = Find(padre[x]);
}

void Union(int x, int y){
	int X = Find(x);
	int Y = Find(y);
	padre[X] = Y;
}

bool sameComponent(int x, int y){
	if(Find(x) == Find(y)) return 1;
	else return 0;
}

bool order(pair<int,int> p1, pair<int,int> p2){
	return p1.first < p2.first;
}

int main(){
	int m, n;
	while(cin>>m>>n && m != 0 && n != 0){

		init(m);

		vector< pair<int,int> > E;
		vector< pair<int,int> > W;

		int total = 0;

		for(int i = 0; i < n; i++){
			int u, v, w;
			cin>>u>>v>>w;
			E.push_back(make_pair(u,v));
			W.push_back(make_pair(w,i));

			total += w;
		}

		sort(W.begin(), W.end(), order);

		int cost = 0;

		for(int i = 0; i < n; i++){
			int u = E[W[i].second].first;
			int v = E[W[i].second].second;
			if(!sameComponent(u,v)){
				Union(u ,v);
				cost += W[i].first;
			}
		}

		int ans = total - cost;

		cout<<ans<<endl;
	}
	return 0;
}