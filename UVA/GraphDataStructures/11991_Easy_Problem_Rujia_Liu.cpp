#include<iostream>
#include<vector>
using namespace std;
#define MAX 1000005

vector<long> V[MAX];

int main(){
	int n, m;
	while(cin>>n>>m){

		for(int i = 0; i <= n; i++) V[i].clear();

		for(int i = 1; i <= n; i++){
			int num;
			cin>>num;
			V[num].push_back(i);
		}

		for(int i = 0; i < m; i++){
			int k, v;
			cin>>k>>v;
			if(k - 1 < V[v].size()) cout<<V[v][k - 1]<<endl;
			else cout<<0<<endl;
		}
	}

	return  0;
}