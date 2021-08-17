#include<iostream>
#include<cstring>
using namespace std;
#define MAX 10005
#define N 22

int C[N];
long long dp[N][MAX];

long long solve(int ind, int mount){
    if(mount == 0) return 1;
    if(mount < 0) return 0;
    if(ind == N) return 0;
    if(dp[ind][mount] != -1) return dp[ind][mount];

    dp[ind][mount] = solve(ind + 1, mount) + solve(ind, mount - C[ind]);

    return dp[ind][mount];
}


int main(){
    for(int i = 0; i < N; i++) C[i] = i*i*i;

    memset(dp, -1, sizeof(dp));

    int mount;
    while(cin>>mount){
        cout<<solve(1, mount)<<endl;
    }
    return 0;
}