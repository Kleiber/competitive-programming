/**
*  Generated by tpp tool
*  File: 599_The_Forrest_For_The_Trees.cpp
*  Created: 28-12-2023 10:40:01
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
using namespace std;


#define MAX 27

vector<vector<int>> graph;
vector<bool> nodes, visited;
int trees, acorns;

// format: (A,B)
void getEdge(string line) {
  char c, u, v;
  stringstream in(line);
  in>>c>>u>>c>>v>>c;
  
  graph[u - 'A'].push_back(v - 'A');
  graph[v - 'A'].push_back(u - 'A');
}

// format: A,B,C,D,E,F,G,H,I,J,K,L,M,N
void getNodes(string line) {
  char u = ' ';
  for(int i = 0; i < line.size(); i++) {
    if(line[i] == ',') {
      nodes[u - 'A'] = 1;
    } else u = line[i];
  }
  nodes[u - 'A'] = 1;
}

int dfs(int u) {
  if(visited[u]) return 0;

  visited[u] = 1;
  int count = 1;
  
  for(int i = 0; i < graph[u].size(); i++) {
    int v = graph[u][i];
    count += dfs(v);
  }

  return count;
}

int main() {
    // do not remove this code if you use cin or cout
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cases;
    string line;

    cin>>cases;
    getline(cin, line);

    while(cases--) {

      graph = vector<vector<int>>(MAX);
      nodes = vector<bool>(MAX);
      visited = vector<bool>(MAX);

      while(getline(cin, line)) {
        if(line[0] != '*') getEdge(line);
        else {
          getline(cin, line);
          getNodes(line);
          break;
        }
      }

      trees = acorns = 0;

      int count = 0;
      for(int i = 0; i < MAX; i++) {
        if(nodes[i] && !visited[i]) {
          count = dfs(i);

          if(count > 1) trees++;
          else acorns++;
        }
      }

      cout<<"There are "<<trees<<" tree(s) and "<<acorns<<" acorn(s)."<<endl;
    }

    return 0;
}

