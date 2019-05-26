#include<algorithm>
#include<vector>
#include<iostream>
#include<cstring>
using namespace std;

vector<string> V;
bool visited[30][80];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

void dfs(int r,int c){
	visited[r][c] = 1;
	V[r][c] = '#';
	
	for(int i = 0; i < 4; i++){
		int nr = r + dy[i];
		int nc = c + dx[i];
		if(!visited[nr][nc] && V[nr][nc] != 'X')
			dfs(nr,nc);
	}
}

int main(){
	int cases;
	string s;
	cin>>cases;
	getline(cin,s);
	for(int i = 0; i < cases; i++){
	
		V.clear();
		memset(visited,0,sizeof(visited));

		while(getline(cin,s) && s[0] != '_') V.push_back(s);
		
		for(int i = 0; i < V.size(); i++){
			for(int j = 0; j < V[i].size(); j++){
				if(V[i][j] == '*' && !visited[i][j]){
					dfs(i,j);
				}
			}
		}
		
		for(int  i = 0; i < V.size(); i++) cout<<V[i]<<endl;
		cout<<"_____"<<endl;
	}
}