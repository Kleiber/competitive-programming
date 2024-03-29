/**
*  Generated by tpp tool
*  File: 1633_Dice_Combinations.cpp
*  Created: 28-02-2024 17:14:39
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


const int MAX = 1e6+5;
const int MOD = 1e9+7;

int N;
int dp[MAX];

int solve(int sum) {
  if(sum < 0) return 0;
  if(sum == 0) return 1;
  if(dp[sum] != -1) return dp[sum];

  dp[sum] = 0;

  for(int d = 1; d <= 6; d++) {
    dp[sum] = (dp[sum] + solve(sum - d)) % MOD;
  }

  return dp[sum];
}

int main() {
    // do not remove this code if you use cin or cout
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    cin>>N;

    cout<<solve(N)<<endl;

    return 0;
}

