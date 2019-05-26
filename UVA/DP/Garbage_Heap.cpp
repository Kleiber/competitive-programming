#include<bits/stdc++.h>
#define MAX 50
using namespace std;
long long int casos, a, b ,c, ans;
long long int dp[MAX][MAX][MAX];

int main(){
	cin>>casos;
	while(casos--){
		cin>>a>>b>>c;
		
		for(int i = 0; i < a; i++){
			for(int j = 0; j < b; j++){
				for(int k = 0; k < c; k++){
					cin>>dp[i][j][k];
					
					if(i > 0) dp[i][j][k] += dp[i - 1][j][k];
					if(j > 0) dp[i][j][k] += dp[i][j - 1][k];
					if(k > 0) dp[i][j][k] += dp[i][j][k - 1];
					if(i > 0 && j > 0) dp[i][j][k] -= dp[i - 1][j - 1][k];
					if(j > 0 && k > 0) dp[i][j][k] -= dp[i][j - 1][k - 1];
					if(i > 0 && k > 0) dp[i][j][k] -= dp[i - 1][j][k - 1];
					if(i > 0 && j > 0 && k > 0) dp[i][j][k] += dp[i - 1][j - 1][k - 1];
				}
			}
		}
		
		ans = -100000000000;
		
		for(int i = 0; i < a; i++){
			for(int j = 0; j < b; j++){
				for(int k = 0; k < c; k++){
					for(int ii = i; ii < a; ii++){
						for(int jj = j; jj < b; jj++){
							for(int kk = k; kk < c; kk++){
								long long int sum = dp[ii][jj][kk];
								
								if(i > 0) sum -= dp[i - 1][jj][kk];
								if(j > 0) sum -= dp[ii][j - 1][kk];
								if(k > 0) sum -= dp[ii][jj][k - 1];
								if(i > 0 && j > 0) sum += dp[i - 1][j - 1][kk];
								if(j > 0 && k > 0) sum += dp[ii][j - 1][k - 1];
								if(i > 0 && k > 0) sum += dp[i - 1][jj][k - 1];
								if(i > 0 && j > 0 && k > 0) sum -= dp[i - 1][j - 1][k - 1];
								
								ans = max(ans, sum);
							}
						}
					}
				}
			}
		}
		
		cout<<ans<<endl;
		if(casos) cout<<endl;
	}
	return 0;
}