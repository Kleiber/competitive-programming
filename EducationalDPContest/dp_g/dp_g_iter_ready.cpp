/**
*  Generated by tpp tool
*  File: dp_g_iter.cpp
*  Created: 27-02-2024 12:08:53
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
vector<bool> visited;
vector<int> ts;
int dp[MAX];

void dfs(int u) {
    visited[u] = 1;

    for(int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if(!visited[v]) dfs(v);
    }

    ts.push_back(u);
}

void topological_sort() {
    for(int i = 1; i <= N; i++) {
        if(!visited[i]) dfs(i);
    }

    reverse(ts.begin(), ts.end());
}

int main() {
    // do not remove this code if you use cin or cout
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>M;

    graph = vector<vector<int>>(N + 1);
    visited = vector<bool>(N + 1, 0);
    ts = vector<int>();

    for(int i = 0; i < M; i++) {
      int u, v;
      cin>>u>>v;

      graph[u].push_back(v);
    }

    topological_sort();

    memset(dp, 0, sizeof(dp));

    for(int i = 0; i < ts.size(); i++) {
        int u = ts[i];

        for(int j = 0; j < graph[u].size(); j++) {
            int v = graph[u][j];
            dp[v] = max(dp[v], 1 + dp[u]);
        }
    }

    int ans = 0;

    for(int i = 1; i <= N; i++) {
        ans = max(ans, dp[i]);
    }

    cout<<ans<<endl;

    return 0;
}
