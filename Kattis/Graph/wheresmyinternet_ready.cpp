/**
*  Generated by tpp tool
*  File: wheresmyinternet.cpp
*  Created: 22-04-2023 22:26:52
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


int main() {
    // do not remove this code if you use cin or cout
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin>>N>>M;

    vector<vector<int>> V(N, vector<int>());
    vector<bool> visited(N, 0);
    
    for(int i = 0; i < M; i++) {
      int a, b;
      cin>>a>>b;
      V[a - 1].push_back(b - 1);
      V[b - 1].push_back(a - 1);
    }

    queue<int> Q;
    Q.push(0);

    while(!Q.empty()) {
      int node = Q.front();
      Q.pop();

      visited[node] = 1;

      for(int i = 0; i < V[node].size(); i++) {
        int child = V[node][i];
        if(!visited[child]) Q.push(child);
      }
    }

    int connected = 1;
    for(int i = 0; i < N; i++) {
      if(!visited[i]) {
        cout<<i + 1<<endl;
        connected = 0;
      }
    }

    if(connected) cout<<"Connected"<<endl;

    return 0;
}
