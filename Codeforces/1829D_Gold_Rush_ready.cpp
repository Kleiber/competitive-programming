/**
*  Generated by tpp tool
*  File: 1829D_Gold_Rush.cpp
*  Created: 06-06-2024 15:23:27
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


map<int, bool> visited;

bool dfs(int n, int m) {
  if(n == m) return 1;
  if(n <= 0) return 0;
  if(n % 3 != 0) return 0;
  if(visited[n]) return 0;

  visited[n] = 1;

  return dfs(n/3, m) || dfs(2 * n/3, m);
}

int main() {
    // do not remove this code if you use cin or cout
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--) {
      int n, m;
      cin>>n>>m;

      visited = map<int, bool>();

      if(dfs(n, m)) cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }

    return 0;
}

