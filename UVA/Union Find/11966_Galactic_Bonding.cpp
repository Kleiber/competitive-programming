#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
#define MAX 1005

struct Point{
	double x, y;
	Point(){}
	Point(double _x, double _y){
		x = _x;
		y = _y;
	}
};

int padre[MAX];

void init(int n){
	for(int i = 0; i  < n; i++) padre[i] = i;
}

int find(int x){
	if(x == padre[x]) return x;
	else return padre[x] = find(padre[x]);
}

void join(int x, int y){
	int X = find(x);
	int Y = find(y);
	padre[X] = Y;
}

int main(){
	int T;
	cin>>T;
	for(int cases = 1; cases <= T; cases++){
		int N;
		double D;
		cin>>N>>D;

		vector<Point> P;

		for(int i = 0; i < N; i++){
			double x, y;
			cin>>x>>y;
			P.push_back(Point(x,y));
		}

		init(N);

		for(int i = 0; i  < N; i++){
			for(int j = i + 1; j < N; j++){
				if(hypot(P[j].x - P[i].x, P[j].y - P[i].y) <= D) join(i, j);
			}
		}

		int ans = 0;
		for(int i = 0; i < N; i++){
			if(padre[i] == i) ans++;
		}

		cout<<"Case "<<cases<<": "<<ans<<endl;
	}

	return 0;
}