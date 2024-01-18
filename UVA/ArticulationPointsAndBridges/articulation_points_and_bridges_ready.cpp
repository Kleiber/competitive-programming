/**
*  Generated by tpp tool
*  File: articulation_points_and_bridges.cpp
*  Created: 17-01-2024 11:17:24
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


#define UNVISITED -1

vector<vector<int>> graph;
vector<int> dfs_num, dfs_low, dfs_parent;
vector<bool> isArticulationPoint;
vector<pair<int,int>> bridges;
int dfs_root, root_children, timer;

void articulationPointsAndBridges(int u) {
  // num and low initialization
  dfs_num[u] = dfs_low[u] = timer++;

  // explore all children nodes
  for(int i = 0; i < graph[u].size(); i++) {
    // children node
    int v = graph[u][i];

    // Check if the children node is unvisited
    if(dfs_num[v] == UNVISITED) {
      // Save de parent node
      dfs_parent[v] = u;

      // Count root's children to check the special Case
      if(u == dfs_root) root_children++;

      // Expand the exploration for the children nodes
      articulationPointsAndBridges(v);

      // check if the node u is an articulation point
      if(dfs_low[v] >= dfs_num[u]) isArticulationPoint[u] = 1;
      // check if the edge u->v is a bridge
      if(dfs_low[v] > dfs_num[u]) bridges.push_back(make_pair(u, v));

      // update subtree low information
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    } else {
      // If non-trivial cycle, update low information
      if(v != dfs_parent[u]) dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
  }
}

int main() {
    // do not remove this code if you use cin or cout
    ios::sync_with_stdio(false);
    cin.tie(0);

    // Graph
    int V = 7;
    int E = 8;

    graph = vector<vector<int>>(V);

    graph[0] = vector<int>{1, 2};
    graph[1] = vector<int>{0, 2};
    graph[2] = vector<int>{0, 1, 3};
    graph[3] = vector<int>{2, 4};
    graph[4] = vector<int>{3, 5, 6};
    graph[5] = vector<int>{4, 6};
    graph[6] = vector<int>{4, 5};

    /*
     * Initial graph with V = 7 and E = 8

       0 ---- 1
        \     |
         \    |
          \   |
           \  |  
             2
             |
             |
             |
             3 --- 4 ---- 5
                    \     |
                     \    |
                      \   |
                       \  |
                         6
    */

    // Initialization

    dfs_num = vector<int>(V, UNVISITED);
    dfs_low = vector<int>(V, UNVISITED);
    dfs_parent = vector<int> (V, UNVISITED);

    isArticulationPoint = vector<bool> (V, 0);
    bridges = vector<pair<int,int>>();

    for(int i = 0; i < V; i++) {
      if(dfs_num[i] == UNVISITED){
        dfs_root = i;
        root_children = 0;
        
        articulationPointsAndBridges(i);
        
        // Check special root case
        isArticulationPoint[dfs_root] = (root_children > 1);
      }
    }

    /*
     * Print Articulation Points
     * Output: 
       Node '2' is an articulation point
       Node '3' is an articulation point
       Node '4' is an articulation point


         0 ---- 1
          \     |
           \    |
            \   |
             \  |
              2 Point
              |
              |
              |   Point  
        Point 3 --- 4 ---- 5
                     \     |
                      \    |
                       \   |
                        \  |
                          6
    */

    for(int i = 0; i < V; i++) {
      if(isArticulationPoint[i]) cout<<"Node '"<<i<<"' is an articulation point"<<endl;
    }

    /* 
     * Print Bridges
     * Output:
       Edge 3 -> 4 is a bridge
       Edge 2 -> 3 is a bridge
      
      
         0 ---- 1
          \     |
           \    |
            \   |
             \  |
               2
               |
        bridge | 
               |
               3 --- 4 ---- 5
                      \     |
               bridge  \    |
                        \   |
                         \  |
                           6
    */

    for(int i = 0; i < bridges.size(); i++) {
      cout<<"Edge "<<bridges[i].first<<" -> "<<bridges[i].second<<" is a bridge"<<endl;
    }

    return 0;
}

