#include<bits/stdc++.h>
#define MAX 105
using namespace std;
long long int casos, cont, N, M, K, ans, sum, area;
long long int dp2[MAX][MAX];
long long int dp1[MAX];

int main(){
	cin>>casos;
	cont = 1;
	while(casos--){
		cin>>N>>M>>K;
		
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				cin>>dp2[i][j];
			}
		}
		
		ans = 0, area = 0;
		for(int i = 0; i < N; i++){
			memset(dp1, 0, sizeof(dp1));
			
			for(int j = i; j < N; j++){
				for(int k = 0; k < M; k++){
					dp1[k] += dp2[j][k];
				}
				
				int h = 0;
				sum = 0;
				for(int k = 0; k < M; k++){
					sum += dp1[k];
					
					while(sum > K) sum -= dp1[h++];
					
					long long aux = (j - i + 1)*(k - h + 1);
					
					if(aux > area){
						area = aux;
						ans = sum;
					}else{
						if(aux == area) ans = min(ans, sum);
					}
				}
			}
		}
		cout<<"Case #"<<cont++<<": "<<area<<" "<<ans<<endl;
	}
	return 0;
}