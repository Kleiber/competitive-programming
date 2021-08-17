#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
#define MAX 105

int dfsNumberCounter;
int rootChildren;
int dfs_root;
int dfs_num[MAX];
int dfs_low[MAX];
int dfs_parent[MAX];
vector<int> G[MAX];

int articulation[MAX];
vector< pair<int,int> > bridge;

map<string, int> M1;
map<int, string> M2;


void articulationPointAndBridge(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;

	for(int j = 0 ; j < G[u].size(); j++){
		int v = G[u][j];

		if(dfs_num[v] == -1){

			dfs_parent[v] = u;

			if(u == dfs_root) rootChildren++;

			articulationPointAndBridge(v);

			if(dfs_low[v] >= dfs_num[u]) articulation[u] = 1;
			if(dfs_low[v] > dfs_num[u]) bridge.push_back(make_pair(u, v));

			dfs_low[u] = min(dfs_low[u], dfs_low[v]);

		}else{
			if(v != dfs_parent[u]) dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

bool orden(string a, string b){
	return a < b;
}

int main(){
	int N,cases = 0;

	while(cin>>N && N){

		if(cases != 0) cout<<endl;
		cases++;

		for(int i = 0; i < N; i++){
			G[i].clear();
			bridge.clear();
			dfs_parent[i] = -1;
			dfs_num[i] = -1;
			dfs_low[i] = -1;
			articulation[i] = 0;
		}

		int R, id = 0;

		for(int i = 0; i < N; i++){
			string location;
			cin>>location;
			M1[location] = id;
			M2[id] = location;
			id++;
		}

		cin>>R;
		for(int i = 0; i < R; i++){
			string location_a, location_b;
			cin>>location_a>>location_b;
			G[M1[location_a]].push_back(M1[location_b]);
			G[M1[location_b]].push_back(M1[location_a]);
		}	

		dfsNumberCounter = 0;

		for(int i = 0; i < N; i++){
			if(dfs_num[i] == -1){
				dfs_root = i;
				rootChildren = 0;
				articulationPointAndBridge(i);
				articulation[i] = (rootChildren > 1);
			}
		}

		int sum = 0;
		vector<string> list;

		for(int i = 0; i < N; i++){
			if(articulation[i]){
				sum++;
				list.push_back(M2[i]);
			}
		}

		cout<<"City map #"<<cases<<": "<<sum<<" camera(s) found"<<endl;

		sort(list.begin(), list.end(), orden);

		for(int i = 0; i < list.size(); i++) cout<<list[i]<<endl;
	}
}