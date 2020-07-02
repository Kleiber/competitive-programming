#include<iostream>
#include<cstring>
using namespace std;
#define MAX 205

int N, Q, M, D;
int A[MAX];
int dp[MAX][MAX][MAX];

int solve(int ind, int sum, int size){
    if(size == M && sum == 0) return 1;
    if(size == M && sum != 0) return 0;
    if(ind == N) return 0;
    if(dp[ind][sum][size] != -1) return dp[ind][sum][size];

    dp[ind][sum][size] = solve(ind + 1, sum%D, size) + solve(ind + 1, (sum + A[ind])%D, size + 1);

    return dp[ind][sum][size];
}

int main(){
    int cases = 1;
    while(cin>>N>>Q){

        if(N == 0 && Q == 0) break;

        for(int i = 0; i < N; i++) cin>>A[i];

        cout<<"SET "<<cases<<":"<<endl;
        for(int i = 0; i < Q; i++){
            cin>>D>>M;
            memset(dp, -1, sizeof(dp)); 
            cout<<"QUERY "<<(i+1)<<": "<<solve(0, 0, 0)<<endl;
        }

        cases++;
    }
    return 0;
}