#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#define MAX 55
using namespace std;
int n,m,e;
bool f = 0;
vector< pair<int,int> > V;

int main(){
	
	cin>>n>>m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>e;
			if(e == 1) V.push_back(make_pair(i,j));
		}
	}
	
	for(int i = 0; i < V.size(); i++){
		if(V[i].first == 0 || V[i].second == 0 || (V[i].first == n - 1) || (V[i].second == m - 1)){
			f = 1;
			break;
		}
	}
	
	if(f) cout<<2<<endl;
	else cout<<4<<endl;
	
	
	return 0;
}