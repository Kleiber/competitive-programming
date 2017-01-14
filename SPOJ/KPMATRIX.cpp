#include<stdio.h>
#include<cstring>
#include<iostream>
#include<algorithm>
#define MAX 260
using namespace std;
int R,C,A,B;
int M[MAX][MAX];
int sum[MAX], sumA[MAX], sumB[MAX];
int V[4*MAX], T[4*MAX];

int add(int i, int r){
	while(i <= r){
		T[i]++;
		i += i&(-i);
	}
}

int query(int i){
	int acum = 0;
	while(i >= 1){
		acum += T[i];
		i -= i&(-i);
	}
	return acum;
}

int main(){
	
	while(scanf("%d %d\n", &R, &C) == 2){
	
		for(int j = 1; j <= C; j++) M[0][j] = 0;
		
		for(int i = 1; i <= R; i++){
			for(int j = 1; j <= C; j++){
				scanf("%d", &M[i][j]);
				
				M[i][j] = M[i][j] + M[i - 1][j];
			}
		}
		
		scanf("%d %d", &A, &B);
		
		int ans = 0;
		
		for(int i = 1; i <= R; i++){
			for(int j = i; j <= R; j++){
				int t1 = 1;
				
				sum[0] = 0;
				sumA[0] = sum[0] - A;
				sumB[0] = sum[0] - B - 1;
				
				V[t1++] = sum[0];
				V[t1++] = sumA[0];
				V[t1++] = sumB[0];
				
				for(int k = 1; k <= C; k++){
					sum[k] = sum[k - 1] + (M[j][k] - M[i - 1][k]);
					sumA[k] = sum[k] - A;
					sumB[k] = sum[k] - B - 1;
				
					V[t1++] = sum[k];
					V[t1++] = sumA[k];
					V[t1++] = sumB[k];
				}

				sort(V + 1, V + t1);
				
				int t2 = 2;
				for(int k = 2; k < t1; k++){
					if(V[k] != V[k -1]) V[t2++] = V[k];
				}
				t2--;
				
				memset(T, 0, sizeof(T));
				
				int ind = lower_bound (V + 1, V + t2, sum[0]) - V;
				add(ind, t2);
				
				for(int k = 1; k <= C; k++){
					int a = lower_bound (V + 1, V + t2, sumA[k]) - V;
					int b = lower_bound (V + 1, V + t2, sumB[k]) - V;
					
					ans += query(a) - query(b);
					
					ind = lower_bound (V + 1, V + t2, sum[k]) - V;
					add(ind, t2);
				}
			}
		}
		
		printf("%d\n", ans);
	}
	return 0;
}