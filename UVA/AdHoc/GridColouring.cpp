#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define F 30
#define C 80
using namespace std;

bool visited[F][C];
vector<string> M;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

void dfs(int r,int c, char p){
	visited[r][c] = 1;
	M[r][c] = p;
	
	for(int i = 0; i < 4; i++){
		int nr = r + dy[i];
		int nc = c + dx[i];
		if(!visited[nr][nc] && M[nr][nc] != 'X')
			dfs(nr,nc,p);
	}
}

int main(){
	string s;
	while(getline(cin,s)){
		if(s[0] != '_')
			M.push_back(s);
		else{
			memset(visited,0,sizeof(visited));
			
			for(int i = 0; i < M.size(); i++){
				for(int j = 0; j < M[i].size(); j++){
					if(M[i][j] != 'X' && M[i][j] != ' ' && !visited[i][j])
						dfs(i,j,M[i][j]);
				}
			}
			
			for(int i = 0; i < M.size(); i++) cout<<M[i]<<endl;
			cout<<"_____________________________"<<endl;
			M.clear();
		}
		
	}
	return 0;
}