#include<bits/stdc++.h>
#define MAX 500
#define INF 10000000
using namespace std;
int casos, N, sum, ans;
int dp[MAX][MAX];

int main(){
	cin>>casos;
	while(casos--){
		cin>>N;
		
		for(int i = 0; i < N * 2; i++){
			for(int j = 0; j < N * 2; j++){
				if(i < N && j < N){
					cin>>dp[i][j];
					dp[i + N][j] = dp[i][j + N] = dp[i + N][j + N] = dp[i][j];
				}
				if(i > 0) dp[i][j] += dp[i - 1][j];
				if(j > 0) dp[i][j] += dp[i][j - 1];
				if(i > 0 && j > 0) dp[i][j] -= dp[i - 1][j - 1];
			}
		}
		
		ans = -INF;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				for(int l = i; l < i + N; l++){
					for(int r = j; r < j + N; r++){
						int sum = dp[l][r];
						if(i > 0) sum -= dp[i - 1][r];
						if(j > 0) sum -= dp[l][j - 1];
						if(i > 0 && j > 0) sum += dp[i - 1][j - 1];
				
						ans = max(ans, sum);
					}
				}
			}
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}