/**
*  Generated by tpp tool
*  File: dp_g_rec.cpp
*  Created: 27-02-2024 12:08:57
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


const int MAX = 1e5 + 5;

int N, M;
vector<vector<int>> graph;
int dp[MAX];

int solve(int u) {
  if(dp[u] != -1) return dp[u];

  dp[u] = 0;

  for(int i = 0; i < graph[u].size(); i++) {
    int v = graph[u][i];
    dp[u] = max(dp[u], 1 + solve(v));
  }

  return dp[u];
}

int main() {
    // do not remove this code if you use cin or cout
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    cin>>N>>M;

    graph = vector<vector<int>>(N + 1);

    for(int i = 0; i < M; i++) {
      int u, v;
      cin>>u>>v;

      graph[u].push_back(v);
    }

    int ans = 0;

    for(int i = 1; i <= N; i++) {
      ans = max(ans, solve(i));
    }

    cout<<ans<<endl;

    return 0;
}

