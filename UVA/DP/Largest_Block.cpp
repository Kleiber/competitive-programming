#include<bits/stdc++.h>
#define MAX 105
#define INF 10000000
using namespace std;
int casos, N, b, r1, c1, r2, c2, ans, sum;
int M[MAX][MAX];
int dp[MAX];

int main(){
	cin>>casos;
	while(casos--){
		cin>>N>>b;
		
		for(int i = 0; i < MAX; i++){
			for(int j = 0; j < MAX; j++){
				M[i][j] = 1;
			}
		}
		
		for(int i = 0; i < b; i++){
			cin>>r1>>c1>>r2>>c2;
			for(int i = r1; i <= r2; i++){
				for(int j = c1; j <= c2; j++){
					M[i][j] = -INF;
				}
			}
		}
		
		ans = 0;
		
		for(int i = 1; i <= N; i++){
			memset(dp, 0, sizeof(dp));
			
			for(int j = i; j <= N; j++){
				for(int k = 1; k <= N; k++){
					dp[k] += M[j][k];
				}
				
				sum = 0;
				for(int k = 1; k <= N; k++){
					sum += dp[k];
					ans = max(ans, sum);
					
					if(sum < 0) sum = 0;
				}
			}
		}
		
		cout<<ans<<endl;
	}
	return 0;
}