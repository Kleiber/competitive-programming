#include<iostream>
#include<cstring>
#include<sstream>
#define MAX 50
using namespace std;
long long N, K, L, t, ans, MOD;
struct Matrix{ long long M[MAX][MAX]; };

Matrix MatMul(Matrix a, Matrix b){
	Matrix ans;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			ans.M[i][j] = 0;
			for(int k = 0; k < N; k++){
				ans.M[i][j] += (a.M[i][k] * b.M[k][j]) % MOD;
			}
		}
	}
	return ans;
}

Matrix MatPow(Matrix base, long long p){
	Matrix ans;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			ans.M[i][j] = (i == j);		
		}
	}

	while(p){
		if(p % 2 == 1) ans = MatMul(ans, base);
		base = MatMul(base, base);
		p >>=  1;
	}
	
	return ans;
}

int pot(int base, int p){
	if(p == 0) return 0;
	else{
		if(p == 1) return base;
		else{
			int res = pot(base, p/2);
			res *= res;
			if(p % 2 == 1) res *= base;
			
			return res;
		}
	}
}

int main(){
	cin>>t;
	while(t--){
		cin>>N>>K>>L;
		
		MOD = pot(10, K);
		
		if(L < N) ans = L % MOD;
		else{
			Matrix A, B;
			
			for(int i = 0; i < N; i++){
				B.M[i][0] = 1;
				for(int j = 1; j < N; j++){
					if(j == i + 1) B.M[i][j] = 1;
					else B.M[i][j] = 0;
				}
			}
			
			for(int j = 0; j < N; j++) A.M[0][j] = N - 1 - j;
			
			for(int i = 1; i < N; i++){
				for(int j = 0; j < N; j++){
					A.M[i][j] = 0;
				}
			}
		
			Matrix aux = MatPow(B,L - N + 1);
			A = MatMul( A , aux);
			ans = A.M[0][0] % MOD;
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
