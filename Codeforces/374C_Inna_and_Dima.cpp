#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define MAX 2000
#define INF 10000000
using namespace std;
int R,C; 
string S = "DIMA";
vector<string> V(MAX);
int dr[4] = {0, 1, -1, 0};
int dc[4] = {1, 0, 0, -1};
int dp[MAX][MAX];

bool valido(int r, int c){
	return r >= 0 && r < R && c >= 0 && c < C;
}

int dfs(int r, int c, int ind){
	int temp = 0;
	
	if(dp[r][c] != 0) return dp[r][c];
	
	dp[r][c] = INF;
	ind = (ind + 1)  % 4;
	
	for(int i = 0; i < 4; i++){
		int nr = r + dr[i];
		int nc = c + dc[i];

		if(valido(nr,nc) && V[nr][nc] == S[ind])
			temp = max(temp, dfs(nr,nc,ind));
	}
	
	return dp[r][c] = min(temp + 1, INF);
}

int main(){
	int ans = 0;
	cin>>R>>C;
	for(int i = 0; i < R; i++) cin>>V[i];
	
	memset(dp, 0, sizeof(dp));
	
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			if(V[i][j] == 'D'){
				ans = max(ans, dfs(i, j, 0));
			}
		}
	}
	
	if(ans < 4)  cout<<"Poor Dima!"<<endl;
	else{
		if(ans == INF) cout<<"Poor Inna!"<<endl;
		else cout<<ans/4<<endl;
	}
	
	return 0;
}