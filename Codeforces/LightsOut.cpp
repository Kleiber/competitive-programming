#include<iostream>
#include<vector>
using namespace std;
int f[4] = {-1,0,1,0};
int c[4] = {0,1,0,-1};
int M[3][3];
vector<string> V(3,"111");

bool existe(int r, int c){
	return r >= 0 && r < 3 && c >= 0 && c  < 3;
}
int main(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++) cin>>M[i][j];
	}

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(M[i][j] > 0  & M[i][j] % 2 != 0){
				for(int k = 0; k < 4; k++){
					int nf = i + f[k];
					int nc = j + c[k];
					if(existe(nf,nc)){
						V[nf][nc] = V[nf][nc] == '0'? '1' : '0';
					}						
				}
				V[i][j] = V[i][j] == '0'? '1' : '0';
			}
		}
	}
	
	for(int i = 0; i < V.size(); i++) cout<<V[i]<<endl;
	return 0;
}