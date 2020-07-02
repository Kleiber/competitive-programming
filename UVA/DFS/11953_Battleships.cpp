#include <iostream>
#include <cstring>
using namespace std;
#define MAX 105

string M[MAX];
bool visited[MAX][MAX];
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int N;

bool valid(int r, int c){
	return r >= 0 && r < N && c >= 0 && c < N;
}

void dfs(int r, int c){
	visited[r][c] = 1;
	for(int i = 0; i < 4; i++){
		int nr = r + dr[i];
		int nc = c + dc[i];
		if(valid(r,c) && !visited[r][c] && M[nr][nc] != M[r][c]) dfs(nr, nc);
	}
}

int main(){
	int cases;
	cin>>cases;

	for(int k = 1; k <= cases; k++){
		cin>>N;

		memset(visited, 0, sizeof(visited));

		for(int i = 0; i < N; i++) cin>>M[i];

		int ans = 0;

		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(!visited[i][j] && M[i][j] == 'x'){
					dfs(i,j);
					ans++;
				}
			}
		}

		cout<<"Case "<<k<<": "<<ans<<endl;
	}
	return 0;
}