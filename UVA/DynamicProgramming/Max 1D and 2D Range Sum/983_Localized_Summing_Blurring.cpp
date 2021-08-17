#include<bits/stdc++.h>
#define MAX 1005
using namespace std;
long int N, M, sum, K;
long int dp[MAX][MAX], ans[MAX][MAX];

int main(){	
	int casos = 0;
	while(cin>>N>>M){
		if(casos++) cout<<endl;
	
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				cin>>dp[N - i - 1][j];
			}
		}
		
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(i > 0) dp[i][j] += dp[i - 1][j];
				if(j > 0) dp[i][j] += dp[i][j - 1];
				if(i > 0 && j > 0) dp[i][j] -= dp[i - 1][j - 1];
			}
		}
		
		sum = 0;
		K = N - M + 1;
		
		for(int i = 0; i < K; i++){
			for(int j = 0; j < K; j++){
				ans[i][j] = dp[i + M - 1][j + M - 1];
				if(i > 0) ans[i][j] -= dp[i - 1][j + M - 1];
				if(j > 0) ans[i][j] -= dp[i + M - 1][j - 1];
				if(i > 0 && j > 0) ans[i][j] += dp[i - 1][j - 1];
			}
		}
		
		for(int i = 0; i < K; i++){
			for(int j = 0; j< K; j++){
				cout<<ans[K - i - 1][j]<<endl;
				sum += ans[i][j];
			}
		}
		cout<<sum<<endl;
	}
	
	return 0;
}