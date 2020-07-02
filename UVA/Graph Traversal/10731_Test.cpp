#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define MAX 30

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int num_scc;
int dfsNumberCounter;
bool visited[MAX];
int dfs_num[MAX];
int dfs_low[MAX];
vector<int> G[MAX], L[MAX];
stack<int> S;

map<char, int> M1;
map<int, char> M2;


void tarjan(int u){
	dfs_num[u] = dfs_low[u] = dfsNumberCounter++;
	visited[u] = 1;
	S.push(u);

	for(int j = 0; j < G[u].size(); j++){
		int v = G[u][j];
		if(dfs_num[v] == -1) tarjan(v);
		if(visited[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}

	if(dfs_low[u] == dfs_num[u]){
		while(1){
			int v = S.top();
			S.pop();
			visited[v] = 0;
			L[num_scc].push_back(v);
			if(u == v) break;
		}
		num_scc++;
	}
}

void init(){
	for(int i = 0; i < alphabet.size(); i++){
		M1[alphabet[i]] = i;
		M2[i] = alphabet[i];
	}
}

bool orden(pair<int,int> a, pair<int,int> b){
	if(a.first < b.first) return 1;
	else return 0;
}

int main(){
	init();

	int n, l = 0;
	int B[MAX];

	while(cin>>n && n != 0){

		if(l != 0) cout<<endl;
		l++;

        for(int i = 0; i < MAX; i++){
        	G[i].clear();
        	L[i].clear();
        	B[i] = -1;
        	dfs_num[i] = -1;
        	dfs_low[i] = -1;
        	visited[i] =  0;
        }

        for(int i = 0; i < n; i++){
        	char ans, A[5];
        	for(int j = 0; j < 5; j++) cin>>A[j];
        	cin>>ans;
        	for(int j = 0; j < 5; j++){
        		if(M1[A[j]] != M1[ans]) G[M1[ans]].push_back(M1[A[j]]);
        		B[M1[A[j]]]++;
        	}
        }

        vector<int> letters;
        for(int i = 0; i < MAX; i++){
        	if(B[i] >= 0) letters.push_back(i);
        }


        for(int i = 0; i < letters.size(); i++){
        	set<int> SS;
        	for(int j = 0; j < G[letters[i]].size(); j++) SS.insert(G[letters[i]][j]);
        	vector<int> SSS(SS.begin(), SS.end());
        	G[letters[i]] = SSS;
        }
        
		num_scc = 0;
		dfsNumberCounter = 0;

		for(int i = 0; i < letters.size(); i++){
			if(dfs_num[letters[i]] == -1) tarjan(letters[i]);
		}

		vector< pair<int,int> > list;
		for(int i = 0; i < num_scc; i++){
			sort(L[i].begin(), L[i].end());
			list.push_back(make_pair(L[i][0], i));
		}

		sort(list.begin(), list.end(), orden);

		for(int i = 0; i < list.size(); i++){
			for(int j = 0; j < L[list[i].second].size(); j++){
				if(j == 0) cout<<M2[L[list[i].second][j]];
				else cout<<" "<<M2[L[list[i].second][j]];
			}cout<<endl;
		}
	}
	return 0;
}