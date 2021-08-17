#include<iostream>
using namespace std;
#define MAX 50005

int padre[MAX];

void init(int n){
	for(int i = 0; i < n; i++) padre[i] = i;
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
	int n, m, cases = 1;
	while(cin>>n>>m && m != 0 && n != 0){

		init(n);

		for(int i = 0; i < m; i++){
			int u, v;
			cin>>u>>v;
			join(u, v);
		}

		int ans = 0;
		for(int i = 0; i < n; i++){
			if(padre[i] == i) ans++;
		}

		cout<<"Case "<<cases<<": "<<ans<<endl;
		cases++;
	}

	return 0;
}