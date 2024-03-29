/**
*  Generated by tpp tool
*  File: 1634_Minimizing_Coins.cpp
*  Created: 28-02-2024 17:34:21
**/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;


const int INF = 1e9+5;
const int MAX = 1e6+5;

int N, X;
vector<int> C;
int dp[MAX];
 
int solve(int amount) {
  if(amount == 0) return 0;
  if(dp[amount] != -1) return dp[amount];

  dp[amount] = INF;

  for(int i = 0; i < N; i++) {
    if(amount >= C[i]) {
      dp[amount] = min(dp[amount], 1 + solve(amount - C[i]));
    }
  }

  return dp[amount];
}
 
int main(){
    // do not remove this code if you use cin or cout
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    cin>>N>>X;

    C = vector<int>(N);

    for(int i = 0; i < N; i++) cin>>C[i];

    int ans = solve(X);

    if(ans == INF) cout<<-1<<endl;
    else cout<<ans<<endl;
 
    return 0;
}

