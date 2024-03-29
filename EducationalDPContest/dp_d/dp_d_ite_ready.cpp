/**
*  Generated by tpp tool
*  File: dp_d_ite.cpp
*  Created: 26-02-2024 23:23:35
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


const int MAX = 1e5+5;

int N, W;
int w[MAX], v[MAX];
long long dp[105][MAX];

void solve() {
  memset(dp, 0, sizeof(0));

  for(int pos = 1; pos <= N; pos++) {
    for(int weight = 0; weight <= W; weight++) {
      if(weight + w[pos] <= W) {
        dp[pos + 1][weight + w[pos]] = max(dp[pos + 1][weight + w[pos]], v[pos] + dp[pos][weight]);
      }

      dp[pos + 1][weight] = max(dp[pos + 1][weight], dp[pos][weight]);
    }
  }

  cout<<dp[N + 1][W]<<endl;
}

int main() {
    // do not remove this code if you use cin or cout
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>W;

    for(int i = 1; i <= N; i++) cin>>w[i]>>v[i];

    solve();

    return 0;
}
