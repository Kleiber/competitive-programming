#include<bits/stdc++.h>
#define MAX 105
using namespace std;
int N;
long long ans, sum;
long long dp1[MAX];
long long dp2[MAX][MAX];

int main(){
	cin>>N;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin>>dp2[i][j];
		}
	}
	
	ans = 0;
	
	for(int i = 0; i < N; i++){
		memset(dp1, 0, sizeof(dp1));
		
		for(int j = i; j < N; j++){
			for(int k = 0; k < N; k++){
				dp1[k] += dp2[j][k];
			}
			
			sum = 0;
			for(int k = 0; k < N; k++){
				sum += dp1[k];
				ans = max(ans, sum);
				
				if(sum < 0) sum = 0;
			}
		}	
	}
	
	cout<<ans<<endl;
	
	return 0;
}