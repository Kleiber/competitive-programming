#include<bits/stdc++.h>
#define MAX 30
#define INF 10000000
using namespace std;
int casos, ans, sum, N;
string s;
vector<string> V;
int dp[MAX];

int main(){
	cin>>casos;
	getline(cin, s);
	getline(cin, s);
	while(casos--){
	
		V.clear();
		N = 0;
		
		while(getline(cin,s) && s.size() > 0){
			V.push_back(s);
			N++;
		}
		
		ans = 0;
		
		for(int i = 0; i < N; i++){
			memset(dp, 0, sizeof(dp));
			
			for(int j = i; j < N; j++){
				for(int k = 0; k < N; k++){
					if(V[j][k] == '0') dp[k] += -INF;
					else  dp[k] += 1;
				}
				
				sum = 0;
				for(int k = 0; k < N; k++){
					sum += dp[k];
					ans = max(ans, sum);
					
					if(sum < 0) sum = 0;
				}
			}
		}
		
		cout<<ans<<endl;
		if(casos) cout<<endl;
	}
	
}