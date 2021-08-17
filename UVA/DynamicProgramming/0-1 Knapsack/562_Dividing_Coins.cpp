#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
#define MAX 105

int N, T;
int C[MAX];
int dp[MAX][50005];

int solve(int ind, int mount){

    if(mount > T/2) return 0;
    if(ind == N) return mount;
    if(dp[ind][mount] != -1) return dp[ind][mount];

    dp[ind][mount] = max(solve(ind + 1, mount), solve(ind + 1, mount + C[ind]));

    return dp[ind][mount];
}

int main(){
    int cases;
    cin>>cases;
    while(cases--){
        cin>>N;

        T = 0;
        for(int i = 0; i < N; i++){
            cin>>C[i];
            T += C[i];
        }

        memset(dp, -1, sizeof(dp));
        int ans = solve(0, 0);
        cout<<abs(ans - (T - ans))<<endl;
    }
    return 0;
}