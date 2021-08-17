#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX 10005

vector< pair<int,int> > M[MAX];

int main(){
	int r, c;
	while(cin>>r>>c){

		queue<int> Q;
		int cantidad, col, val;

		for(int i = 1; i <= c; i++) M[i].clear();

		for(int i = 1; i <= r; i++){
			cin>>cantidad;

			while(cantidad--){
				cin>>col;
				Q.push(col);
			}

			while(!Q.empty()){
				cin>>val;
				M[Q.front()].push_back(make_pair(i, val));
				Q.pop();
			}
		}

		cout<<c<<" "<<r<<endl;
		for(int i = 1; i <= c; i++){
			cout<<M[i].size();
			for(int j = 0; j < M[i].size(); j++) cout<<" "<<M[i][j].first;
			cout<<endl;
			for(int j = 0; j < M[i].size(); j++){
				if(j) cout<<" ";
				cout<<M[i][j].second;
			}
			cout<<endl;
		}
	}
	return  0;
}