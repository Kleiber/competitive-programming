#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAX 1005

struct city{
    int id;
    double x, y;
	city() {}
    city(int _id, double _x, double _y){
    	id = _id;
    	x  = _x;
    	y  = _y;
    }
};

struct nodo{
    int u, v;
    double w;
    bool f;
	nodo() {}
    nodo(int _u, int _v, double _w, bool _f){
    	u = _u;
    	v  = _v;
    	w  = _w;
    	f = _f;
    }
};

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

int Component(int n){
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(i == padre[i]) ans++;
	}

	return ans;
}

bool order(nodo n1, nodo n2){
	return n1.w < n2.w;
}

int main(){
	int T;
	cin>>T;

	for(int cases = 1; cases <= T; cases++){
		int n; 
		double r;
		cin>>n>>r;

		init(n);

		vector<city> C;
		for(int i = 0; i < n; i++){
			double x, y;
			cin>>x>>y;
			C.push_back(city(i, x, y));
		}

		vector<nodo> V;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i != j){
					double dist = hypot(C[i].x - C[j].x, C[i].y - C[j].y);
					bool flag = 1;
					if(dist > r) flag = 0;
					V.push_back(nodo(C[i].id, C[j].id, dist, flag));
				}
			}
		}

		sort(V.begin(), V.end(), order);

		double totalRail = 0;
		for(int i = 0; i < V.size(); i++){
			if(V[i].f){
				if(!sameComponent(V[i].u, V[i].v)){
					Union(V[i].u, V[i].v);
					totalRail += V[i].w;
				}
			}
		}

		int states = Component(n);

		double totalRoad = 0;
		for(int i = 0; i < V.size(); i++){
			if(!V[i].f){
				if(!sameComponent(V[i].u, V[i].v)){
					Union(V[i].u, V[i].v);
					totalRoad += V[i].w;
				}	
			}
		}

		cout<<"Case #"<<cases<<": "<<states<<" "<<round(totalRail)<<" "<<round(totalRoad)<<endl;
	}
	return 0;
}