#include<iostream>
#include<cstring>
using namespace std;
#define MAX 105

int M, N;
int W[MAX], V[MAX];
int dp[MAX][100005];

int solve(int ind, int mount){

    if(mount > M && mount <= 2000) return -500;
    if(mount > M + 200)  return -500;
    if(ind == N){
        if(mount > M && mount <= 2000) return -500;
        else return 0;
    }
    if(dp[ind][mount] != -1) return dp[ind][mount];

    dp[ind][mount] = max(solve(ind + 1, mount), V[ind] + solve(ind + 1, mount + W[ind]));

    return dp[ind][mount];
}

int main(){
    while(cin>>M>>N){
        for(int i = 0; i < N; i++) cin>>W[i]>>V[i];

        memset(dp, -1, sizeof(dp));
        cout<<solve(0,0)<<endl;
    }
    
    return 0;
}
