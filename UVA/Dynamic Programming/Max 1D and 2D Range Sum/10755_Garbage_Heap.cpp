#include<bits/stdc++.h>
#define MAX 50
using namespace std;
long long int casos, a, b, c, ans;
long long int dp3[MAX][MAX][MAX];
long long int dp2[MAX][MAX];
long long int dp1[MAX];

int main(){
    cin>>casos;
    while(casos--){
        cin>>a>>b>>c;
		
        for (int i = 0; i < a; i++){
            for (int j = 0; j < b; j++){
                for (int k = 0; k < c; k++){
					cin>>dp3[i][j][k];
				}
			}
		}
		
        ans = -100000000000;
        for (int i = 0; i < a; i++) { // first compression
            memset(dp2, 0, sizeof(dp2));
			
            for (int m = i; m < a; m++){
                for (int j = 0; j < b; j++){
                    for (int k = 0; k < c; k++){
						dp2[j][k] += dp3[m][j][k];
					}
				}
				
                for (int n = 0; n < b; n++) { // second compression
                    memset(dp1, 0, sizeof(dp1));
					
                    for (int j = n; j < b; j++) {
                        for (int k = 0; k < c; k++){
							dp1[k] += dp2[j][k];
						}
						
						long long int sum = 0;
						for(int k = 0; k < c; k++){
							sum += dp1[k];
							ans = max(ans, sum);
							
							if(sum < 0) sum = 0;
						}
                    }
                }
            }
        }
        cout<<ans<<endl;
        if(casos) cout<<endl;
    }
}