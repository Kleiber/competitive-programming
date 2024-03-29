/**
*  Generated by tpp tool
*  File: 1934B_Yet_Another_Coin_Problem.cpp
*  Created: 01-03-2024 12:05:19
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
const int MAX = 30;
const int NUM_COINS = 5;

int cases, n;
vector<int> C {1, 3, 6, 10, 15};
int dp[MAX];
 
int solve(int amount) {
  if(amount == 0) return 0;
  if(dp[amount] != -1) return dp[amount];
 
  dp[amount] = INF;
 
  for(int i = 0; i < NUM_COINS; i++) {
    if(amount >= C[i]) {
      dp[amount] = min(dp[amount], 1 + solve(amount - C[i]));
    }
  }
 
  return dp[amount];
}

int main() {
    // do not remove this code if you use cin or cout
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    dp[0] = 0;
    int minCoins = solve(MAX - 5);

    int cases;
    cin>>cases;

    while(cases--) {
      int n;
      cin>>n;

      int block = n/15;
      int pos = n % 15;

      int ans = block + dp[pos];

      if(n > 15 && pos == 8) ans = ans - 1;
      if(n > 15 && pos == 5) ans = ans - 2;

      cout<<ans<<endl;
    }

    return 0;
}

