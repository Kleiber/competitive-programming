#include<iostream>
#include<cstring>
#include<sstream>
using namespace std;
#define MAX 30005

int padre[MAX];
int scc[MAX];

void init(int n){
	for(int i = 0; i < n; i++){
		padre[i] = i;
		scc[i] = 0;
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
}


int main(){
	int n, m;
	while(cin>>n>>m){
		if(n == 0 && m == 0) break;

		init(n);

		for(int i = 0; i < m; i++){
			int k, curr, last;
			cin>>k;
			for(int j = 0; j < k; j++){
				cin>>curr;
				if(j != 0) join(curr, last);
				last = curr;
			}
		}

		int ans = find(0);
		for(int i = 0; i < n; i++) scc[find(i)]++;

		cout<<scc[ans]<<endl;
	}
	return 0;
}