/**
*  Generated by tpp tool
*  File: 11906_Knight_In_A_War_Grid.cpp
*  Created: 31-12-2023 15:29:14
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


#define MAX 105
#define MOV 8
#define WATER -1

struct node {
  int row;
  int col;
  
  bool operator==(const node &n) const{
    return make_pair(row, col) == make_pair(n.row, n.col);
  }

  bool operator<(const node &n) const {
    return make_pair(row, col) < make_pair(n.row, n.col);
  }
};

int t, R, C, M, N, W;
int x, y, cases;
int graph[MAX][MAX], visited[MAX][MAX];

bool isValid(int r, int c) {
  return r >= 0 && r < R && c >= 0 && c < C;
}

int main() {
    // do not remove this code if you use cin or cout
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    cases = 1;

    while(t--) {
      memset(graph, 0, sizeof(graph));
      memset(visited, 0, sizeof(visited));
      
      cin>>R>>C>>M>>N;
      
      cin>>W;
      for(int i = 0; i < W; i++) {
        cin>>x>>y;
        graph[x][y] = WATER;
      }

      // BFS
      int dr[] = {M, M, -M, -M, N, N, -N, -N};
      int dc[] = {N, -N, N, -N, M, -M, M, -M};

      queue<node> Q;
      Q.push(node{0, 0});
      visited[0][0] = 1;

      while(!Q.empty()) {
        node u = Q.front();
        Q.pop();

        // Just to avoid duplicates
        set<node> S;

        for(int k = 0; k < MOV; k++) {
          int nr = u.row + dr[k];
          int nc = u.col + dc[k];

          S.insert(node{nr, nc});
        }

        for(auto v : S) {
          if(isValid(v.row, v.col) && graph[v.row][v.col] != WATER) {
            graph[v.row][v.col]++;

            if(!visited[v.row][v.col]) {
              visited[v.row][v.col] = 1;
              Q.push(v);
            }
          }
        }
      }

      int evens, odds;
      evens = odds = 0;

      for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
          if((graph[i][j] != -1 && graph[i][j] != 0) || (i == 0 && j == 0)) {
            if(graph[i][j] % 2 == 0) evens++;
            else odds++;
          }
        }
      }

      cout<<"Case "<<cases++<<": "<<evens<<" "<<odds<<endl;
    }

    return 0;
}

