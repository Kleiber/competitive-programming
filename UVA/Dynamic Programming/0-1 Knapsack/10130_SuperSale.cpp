#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1005
#define MAX_M 32

int V[MAX], W[MAX], M[MAX];
int dp[MAX][MAX_M];
int T, P, G;

int solve(int mount){

    for(int i = 0; i <= P; i++) dp[i][0] = 0;
    for(int j = 0; j <= mount; j++) dp[0][j] = 0;

    for(int i = 1; i <= P; i++){
        for(int j = 1; j <= mount; j++){
            if(W[i] > j) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], V[i] + dp[i - 1][j - W[i]]);
        }
    }

    int ans = 0;
    for(int i = 1; i <= G; i++) ans += dp[P][M[i]];

    return ans;
}

int main() {
    cin>>T;
    while(T--){
        int mount = 0;
        cin>>P;
        for(int i = 1; i <= P; i++) cin>>V[i]>>W[i];
        cin>>G;
        for(int i = 1; i <= G; i++){
            cin>>M[i];
            mount = max(mount, M[i]);
        }

        cout<<solve(mount)<<endl;
    }
    return 0;
}