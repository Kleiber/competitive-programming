#include <bits/stdc++.h>
#define MAX 11
using namespace std;
int n;
int M[MAX][MAX];

int Fila(int r, int c, int val){
	for(int i = 0; i < n*n; i++){
		if(M[r][i] == val) return 0;
	}
	return 1;
}

int Columna(int r, int c, int val){
	for(int i = 0; i < n*n; i++){
		if(M[i][c] == val) return 0;
	}
	return 1;
}

int Cuadrado(int r, int c, int val){
	for(int i = r; i < r + n; i++){
		for(int j = c; j < c + n; j++){
			if(M[i][j] == val) return 0;
		}
	}
	return 1;
}

int Solve(int r, int c){
	for(int i = r; i < n*n; i++){
		for(int j = 0; j < n*n; j++){
			if(M[i][j] == 0){
				for(int k = 1; k < n*n + 1; k++){
					if(Fila(i, j, k) && Columna(i, j, k) && Cuadrado(i - i % n, j - j % n, k)){
						M[i][j] = k;
						if (Solve(i, j)) return 1;
						M[i][j] = 0;
					}
				}
				return 0;
			}
		}
	}
	
	return 1;
}

int main(){
	int f = 0;
	while(cin>>n && n){
		if(f) cout<<endl;
		f = 1;
	
		for(int i = 0 ;i < n*n; i++){
			for(int j = 0; j < n*n; j++){
				cin>>M[i][j];
			}
		}
	
		int ans = Solve(0, 0);
	
		if (ans){
			for(int i = 0 ;i < n*n; i++){
				for(int j = 0; j < n*n; j++){
					if(j == n*n - 1) cout<<M[i][j]<<endl;
					else cout<<M[i][j]<<" ";
				}
			}
		}else cout<<"NO SOLUTION"<<endl;

	}
	
	return 0;
}