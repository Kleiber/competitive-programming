#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
#define MAX 250

int R, C;
int M[MAX][MAX];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int holes[MAX];
string letter[6] = {"W", "A", "K", "J", "S", "D"};
map<char, string> hexa;

void fill(int r, int c, char h){
	string s = hexa[h];
	for(int j = 0; j < 4; j++){
		M[r + 1][c + 1 + j] = s[j] - '0';
	}
}

bool valid(int r, int c){
	return r >= 0 && r < R && c >= 0 && c < C;
}

void dfs(int r, int c, int value, int component){
	if(!valid(r, c) || M[r][c] != value) return;
	M[r][c] = component;

	for(int i = 0; i < 4; i++){
		int nr = r + dr[i];
		int nc = c + dc[i];
		dfs(nr, nc, value, component);
	}
}

int main(){

	hexa['0'] = "0000"; hexa['1'] = "0001"; hexa['2'] = "0010"; hexa['3'] = "0011"; hexa['4'] = "0100";
	hexa['5'] = "0101"; hexa['6'] = "0110"; hexa['7'] = "0111"; hexa['8'] = "1000"; hexa['9'] = "1001";
	hexa['a'] = "1010"; hexa['b'] = "1011"; hexa['c'] = "1100"; hexa['d'] = "1101"; hexa['e'] = "1110";  
	hexa['f'] = "1111";

	int H, W, cases = 0;
	while(cin>>H>>W && H != 0 && W != 0){
		R = H + 2;
		C = 4*W + 2;

		memset(M, 0, sizeof(M));
		memset(holes, 0, sizeof(holes));

		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				char hex;
				cin>>hex;
				fill(i, 4*j, hex);
			}
		}

		dfs(0, 0, 0, MAX);

		int component = 2;
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C ; j++){
				if(M[i][j] == 0){
					holes[M[i][j - 1]]++;
					dfs(i, j, M[i][j], M[i][j-1]);
				}else{
					if(M[i][j] == 1) dfs(i, j, M[i][j], component++);
				}
			}
		}

		string ans = "";
		for(int i = 2; i < component; i++) ans += letter[holes[i]];
		sort(ans.begin(), ans.end());
		cout<<"Case "<<++cases<<": "<<ans<<endl;
	}
	return 0;
}