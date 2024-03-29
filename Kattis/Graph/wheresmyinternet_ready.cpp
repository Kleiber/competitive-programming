/**
*  Generated by tpp tool
*  File: wheresmyinternet.cpp
*  Created: 31-12-2023 17:35:28
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


int N, M;
vector<bool> visited;
vector<vector<int>> graph;

void dfs(int u) {
  if(visited[u]) return;

  visited[u] = 1;

  for(int i = 0; i < graph[u].size(); i++) {
    int v = graph[u][i];
    dfs(v);
  }
}

int main() {
    // do not remove this code if you use cin or cout
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;

    graph = vector<vector<int>>(N);
    visited = vector<bool>(N, 0);

    for(int i = 0; i < M; i++) {
      int u, v;
      cin>>u>>v;

      graph[u - 1].push_back(v - 1);
      graph[v - 1].push_back(u - 1);
    }

    dfs(0);

    vector<int> disconnected;
    bool isConnected = 1;

    for(int i = 0; i < N; i++) {
      if(!visited[i]) {
        isConnected = 0;
        disconnected.push_back(i);
      }
    }

    if(isConnected) cout<<"Connected"<<endl;
    else {
      sort(disconnected.begin(), disconnected.end());
      for(int i = 0; i < disconnected.size(); i++) {
        cout<<disconnected[i] + 1<<endl;
      }
    }

    return 0;
}

