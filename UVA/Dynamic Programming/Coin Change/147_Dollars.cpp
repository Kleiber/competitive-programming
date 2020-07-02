#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
#define MAX 30005
#define N 11

long long C[N] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
long long dp[N][MAX];

long long solve(int ind, long long mount){
    if(mount == 0) return 1;
    if(mount < 0) return 0;
    if(ind == N) return 0;
    if(dp[ind][mount] != -1) return dp[ind][mount];

    dp[ind][mount] = solve(ind + 1, mount) + solve(ind, mount - C[ind]);

    return dp[ind][mount];
}

int main(){
    memset(dp, -1, sizeof(dp));

    double money;
    while(cin>>money){
        long long mount = money*10*10;

        if(mount == 0) break;

        long long ans = solve(0, mount);
        printf("%6.2f%17lld\n", money, ans);
    }

    return 0;
}