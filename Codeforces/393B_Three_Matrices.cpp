#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cstring>
#define MAX 170
using namespace std;
int n;
double M[MAX][MAX], A[MAX][MAX], B[MAX][MAX];
bool visitados[MAX][MAX];
int main(){
	memset(M, 0, sizeof(M));
	memset(A, 0, sizeof(A));
	memset(B, 0, sizeof(B));
	memset(visitados, 0, sizeof(visitados));

	cin>>n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>M[i][j];
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j){
				visitados[i][j] = 1;
				A[i][j] = M[i][j];
				B[i][j] = 0.0;
			}else{
				if(!visitados[i][j]){
					visitados[i][j] = 1;
			
					double x = (M[j][i] + M[i][j])/2.0;
					double y = (M[j][i] - M[i][j])/2.0;
					A[i][j] = x;
					A[j][i] = x;
					B[i][j] = -y;
					B[j][i] = y;
					
					visitados[j][i] = 1;
				}
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(j == n - 1) printf("%8f\n",A[i][j]);
			else printf("%8f ",A[i][j]);
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(j == n - 1) printf("%8f\n",B[i][j]);
			else printf("%8f ",B[i][j]);
		}
	}
	return 0;
}
