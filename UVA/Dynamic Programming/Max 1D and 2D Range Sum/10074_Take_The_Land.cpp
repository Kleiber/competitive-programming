#include<bits/stdc++.h>
#define MAX 105
#define INF 10000000
using namespace std;
int R, C, ans, sum;
int M[MAX][MAX];
int dp[MAX];

int main(){
	while(cin>>R>>C && R && C){
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				cin>>M[i][j];
				if(M[i][j]) M[i][j] = -INF;
				else M[i][j] = 1;
			}
		}
		
		ans = 0;
		for(int i = 0; i < R; i++){
			memset(dp, 0, sizeof(dp));
			
			for(int j = i; j < R; j++){
				for(int k = 0; k < C; k++){
					dp[k] += M[j][k];
				}
				
				sum = 0;
				for(int k = 0; k < C; k++){
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