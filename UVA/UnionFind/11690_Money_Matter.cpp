#include<iostream>
using namespace std;
#define MAX 10005

long long W[MAX];
int padre[MAX];

void init(int n){
	for(int i = 0; i < n; i++){
		padre[i] = i;
		W[i] = 0;
	}
}

int find(int x){
	if(x == padre[x]) return x;
	else return padre[x] = find(padre[x]);
}

void join(int x, int y){
	int X = find(x);
	int Y = find(y);
	padre[X] = Y;

	if(X != Y){
		W[Y] = W[Y] + W[X];
		W[X] = 0;
	}
}

int main(){
	int N;
	cin>>N;
	while(N--){
		int n,m;
		cin>>n>>m;

		init(n);

		for(int i = 0; i < n; i++) cin>>W[i];
		for(int i = 0; i < m; i++){
			int u, v;
			cin>>u>>v;
			join(u, v);
		}

		bool ans = 1;
		for(int i = 0; i < n; i++){
			if(W[i] != 0){
				ans = 0;
				break;
			}
		}

		if(ans) cout<<"POSSIBLE"<<endl;
		else cout<<"IMPOSSIBLE"<<endl;
	}

	return 0;
}