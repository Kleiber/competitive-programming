#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define MAX 105

struct Edge{
	double u, v, w;
};

int padre[MAX];
int element[MAX];

void init(){
	for(int i = 0; i < MAX; i++){
		padre[i] = i;
		element[i] = 0;
	}
}

int find(int x){
	if(x == padre[x]) return x;
	else find(padre[x]);
}

void join(int x, int y){
	int X = find(x);
	int Y = find(y);

	padre[Y] = X;
}

double dist(double x1, double y1, double x2, double y2){
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

int main(){
	int n;
	while(cin>>n && n != -1){

		double x[n], y[n], r[n];
		for(int i = 0; i < n; i++) cin>>x[i]>>y[i]>>r[i];

		vector<Edge> V;
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				double d = dist(x[i], y[i], x[j], y[j]);
				if((x[i] == x[j] && y[i] == y[j] && r[i] == r[j]) || (d <= r[i] + r[j] && d >= fabs(r[i] - r[j]))) V.push_back((Edge){i, j, 1.0});
			}
		}

		init();

		for(int i = 0; i < V.size(); i++){
			if(find(V[i].u) != find(V[i].v)) join(V[i].u, V[i].v);
		}

		int ans = 0;
		for(int i = 0; i < n; i++) element[find(i)]++;
		for(int i = 0; i < n; i++) ans = max(ans, element[i]);

		if(ans == 1) cout<<"The largest component contains "<<ans<<" ring."<<endl;
		else cout<<"The largest component contains "<<ans<<" rings."<<endl;

	}
	return 0;
}