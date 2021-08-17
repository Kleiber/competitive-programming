#include<iostream>
#include<vector>
#include<cstring>
#define MAX 15
using namespace std;
int dx[4] ={0,-1,0,1};
int dy[4] ={1,0,-1,0};
int R,C,S;

bool existe(int r, int c){
	return r >= 0 && r < R && c >= 0 && c < C;
}

int direccion(char c){
	if(c == 'S') return 0;
	if(c == 'W') return 1;
	if(c == 'N') return 2;
	if(c == 'E') return 3;
}

int main(){
	
	while(cin>>R>>C>>S && R && C && S){
	
		vector<string> V(MAX);
		int visitados[MAX][MAX];
		
		memset(visitados, 0, sizeof(visitados));
		
		for(int i = 0; i < R; i++) cin>>V[i];
		
		int cont = 1, flag = 0;
		int r = 0,c = S - 1;
		
		while(1){
			if(!existe(r,c)) {flag = 1; break;}
			if(visitados[r][c] != 0) {flag = 2; break;}
				
			visitados[r][c] = cont;
			
			int ind = direccion(V[r][c]);
			r += dy[ind];
			c += dx[ind];
			
			cont++;
		}
		
		if(flag == 1) cout<<cont - 1<<" step(s) to exit"<<endl;
		else cout<<(visitados[r][c] - 1)<<" step(s) before a loop of "<<(cont - visitados[r][c])<<" step(s)"<<endl;
	}
	return 0;
}