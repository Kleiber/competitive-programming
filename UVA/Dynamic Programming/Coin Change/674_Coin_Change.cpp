#include<iostream>
#include<cstring>
using namespace std;
#define MAX 7500
#define N 5

int C[N] = {1, 5, 10, 25, 50};
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
    memset(dp, -1, sizeof(dp));

    int mount;
    while(cin>>mount){
        cout<<solve(0, mount)<<endl;
    }
    return 0;
}