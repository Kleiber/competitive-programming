/**
*  Generated by tpp tool
*  File: reachableroads.cpp
*  Created: 22-04-2023 23:38:36
**/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;


int n, m, r;
vector<vector<int>> G;
vector<bool> visited;

void dfs(int node) {
  visited[node] = 1;

  for(int i = 0; i < G[node].size(); i++) {
    int child = G[node][i];
    if(!visited[child]) dfs(child);
  }
}

int main() {
    // do not remove this code if you use cin or cout
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;

    while(n--) {
      cin>>m;

      G = vector<vector<int>>(m, vector<int>());
      visited = vector<bool>(m, 0);

      cin>>r;
      for(int i = 0; i < r; i++) {
        int u, v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
      }

      int cont = 0;
      for(int i = 0; i < m; i++) {
        if(!visited[i]) {
          dfs(i);
          cont++;
        }
      }

      cout<<cont - 1<<endl;
    }

    return 0;
}

