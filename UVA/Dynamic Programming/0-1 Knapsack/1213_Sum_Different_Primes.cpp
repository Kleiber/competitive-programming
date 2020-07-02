#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define MAX 1200

bool prime[MAX];
vector<int> Primes;

int N, K;
int dp[200][MAX][20];

void sieve(){
    memset(prime, 1, sizeof(prime));
    prime[0] = prime[1] = 0;

    for(int i = 2; i < MAX; i++){
        if(prime[i]){
            for(int j = i*i; j < MAX; j+=i) prime[j] = 0;
            Primes.push_back(i);
        }
    }
}

int solve(int ind, int sum, int size){
    if(size == K && sum < N) return 0;
    if(size == K && sum == N) return 1;
    if(size > K || sum > N) return 0;
    if(Primes[ind] > N) return 0;
    if(dp[ind][sum][size] != -1) return dp[ind][sum][size];

    dp[ind][sum][size] = solve(ind + 1, sum, size) + solve(ind + 1, sum + Primes[ind], size + 1);

    return dp[ind][sum][size];
}

int main(){
    sieve();

    while(cin>>N>>K){
        if(N == 0 && K == 0) break;
        memset(dp, -1, sizeof(dp));
        cout<<solve(0, 0, 0)<<endl;
    }

    return 0;
}