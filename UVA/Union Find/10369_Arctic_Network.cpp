#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stdio.h>
using namespace std;
#define MAX 505

struct Edge{
	int u;
	int v;
	double w;
};

int padre[MAX];

void init(){
	for(int i = 0; i < MAX; i++) padre[i] = i;
}

int find(int x){
	if(x == padre[x]) return x;
	else return padre[x] = find(padre[x]);
}

void join(int x, int y){
	int X = find(x);
	int Y = find(y);

	padre[Y] = X;
}

bool isSame(int x, int y){
	if(find(x) == find(y)) return 1;
	else return 0;
}

bool order(Edge e1, Edge e2){
	return e1.w < e2.w;
}

double dist(double x1, double y1, double x2, double y2){
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main(){
	int N;
	cin>>N;

	while(N--){
		int S, P;
		cin>>S>>P;

		double X[P], Y[P];
		for(int i = 0; i < P; i++) cin>>X[i]>>Y[i];



		vector<Edge> V;
		for(int i = 0; i < P; i++){
			for(int j = i + 1; j < P; j++){
				V.push_back((Edge){i, j, dist(X[i], Y[i], X[j], Y[j])});
			}
		}

		sort(V.begin(), V.end(), order);

		init();

		int components = P;
		double ans = 0;
		
		for(int i = 0; i < V.size(); i++){
			if(components == S) break;
			else{
				if(!isSame(V[i].u, V[i].v)){
					join(V[i].u, V[i].v);
					ans = max(ans, V[i].w);
					components--;
				}
			}
		}

		printf("%.2f\n", ans);
	}
	return 0;
}