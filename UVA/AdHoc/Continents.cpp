#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#define MAX 30
using namespace std;

int R,C;
vector<string> M;
bool visited[MAX][MAX];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

bool validate(int r){
	return r >= 0 && r < R;
}

int dfs(int r, int c){
	visited[r][c] = 1;
	int cont = 1;
	for(int i = 0; i < 4; i++){
		int nc = c + dx[i];
		int nr = r + dy[i];
		
		if(nc == -1) nc = C - 1;
		if(nc == C) nc = 0;
	
		if(validate(nr) && M[r][c] == M[nr][nc] && !visited[nr][nc])
			cont += dfs(nr,nc);
		
	}
	
	return cont;
}

int main(){
	string s;
	int r,c;
	while(cin>>R>>C){
		M= vector<string>(R);
		for(int i = 0; i < R; i++) cin>>M[i];
		
		memset(visited,0,sizeof(visited));
		vector<int> V;
		
		cin>>r>>c;
		int n = dfs(r,c);
		
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				if(M[i][j] == M[r][c] && !visited[i][j]) 
					V.push_back(dfs(i,j));
			}
		}
		
		//for(int i = 0; i < V.size(); i++) cout<<"  "<<V[i]<<endl;
		sort(V.begin(),V.end());
		if(V.size() > 0) cout<<V[V.size()-1]<<endl;
		else cout<<0<<endl;
		M.clear();
	}
	
}