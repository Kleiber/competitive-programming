#include<iostream>
#include<cstring>
using namespace std;
#define MAX 1005

int N;
int W[MAX], M[MAX];
int dp[MAX][3005];

int solve(int ind, int mount){
    if(mount < 0) return 0;
    if(ind == N) return 0;
    if(dp[ind][mount] != -1) return dp[ind][mount];

    int q1 = 0;
    int q2 = 0;

    if(W[ind] <= mount) q1 = 1 + solve(ind + 1, min(mount - W[ind], M[ind]));
    q2 = solve(ind + 1, mount);

    dp[ind][mount] = max(q1, q2);

    return dp[ind][mount];
}

int main(){
    
    while(cin>>N && N){
        for(int i = 0; i < N; i++) cin>>W[i]>>M[i];
        memset(dp, -1, sizeof(dp));

        int ans = 0;
        for(int i = 0; i < N; i++) ans = max(ans, 1 + solve(i + 1, M[i]));
        cout<<ans<<endl;
    }

    return 0;
}